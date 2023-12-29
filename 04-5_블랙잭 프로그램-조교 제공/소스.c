#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* Shuffle();
int* Initialization_user(int*);
int* Initialization_dealer(int*);
void Initialization(int**, int**, int*);
int status(int*, int*, int, int);
int* Hit(int**, int*, int, int);
int* End(int**, int*, int, int);
void Result(int*, int*, int, int);
int card_sum(int*, int);

int main(void) {

    srand((unsigned int)time(NULL));

    while (1) {
        printf("==============================\n");
        printf("Game Start? ");
        char input1[10] = { 0, };
        int card_idx = 0;
        int user_card_cnt = 0;
        int dealer_card_cnt = 0;
        int win_lose_flag = 0;
        scanf("%s", input1);
        if (!strcmp(input1, "End"))
            break;

        else if (!strcmp(input1, "Start")) {
            int* deck = Shuffle();
            int* user = NULL;
            int* dealer = NULL;
            Initialization(&user, &dealer, deck);
            user_card_cnt += 2;
            dealer_card_cnt += 2;
            card_idx += 4;
            win_lose_flag = status(user, dealer, user_card_cnt, dealer_card_cnt);

            while (1) {
                printf("More Card? ");
                char input2[10] = { 0, };
                scanf("%s", input2);
                if (!strcmp(input2, "Hit")) {
                    user = Hit(&user, deck, card_idx, user_card_cnt);
                    card_idx++;
                    user_card_cnt++;
                    win_lose_flag = status(user, dealer, user_card_cnt, dealer_card_cnt);

                    if (win_lose_flag == 1) {
                        printf("Busted! Over21! Dealer Wins.\n");
                        break;
                    }

                    if (win_lose_flag == 3) {
                        printf("Blackjack! Winner Winner Chicken Dinner! User Win!\n");
                        break;
                    }
                }
                else if (!strcmp(input2, "Stay")) {
                    while (card_sum(dealer, dealer_card_cnt) < 17) {
                        dealer = End(&dealer, deck, card_idx, dealer_card_cnt);
                        card_idx++;
                        dealer_card_cnt++;
                        win_lose_flag = status(user, dealer, user_card_cnt, dealer_card_cnt);
                    }
                    if (win_lose_flag == 2) {
                        printf("User Wins! Dealer Busted!\n");
                        break;
                    }

                    if (win_lose_flag == 4) {
                        printf("Blackjack! User Lose.\n");
                        break;
                    }

                    else {
                        Result(user, dealer, user_card_cnt, dealer_card_cnt);
                        break;
                    }
                }
            }
        }
        else
            printf("Error: Wrong Input, Try Again.\n");
    }
    printf("==============================\n");
    _CrtDumpMemoryLeaks(); //메모리 누수 감지를 위한 함수
    return 0;
}


int* Shuffle() {

    int* deck = malloc(sizeof(int) * 20);

    int card_check[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 }; //각 index 별로 카드의 갯수 의미 차례대로 A~K

    for (int i = 0; i < 20; i++) {
        //난수 발생 시 카드 4장 이상 만들지 않기 위한 loop문
        while (1) {
            int card = rand() % 13 + 1;
            //printf("%d ", card);
            if (card_check[card] < 4) {
                deck[i] = card;
                card_check[card] = card_check[card] + 1;
                break;
            }
        }
    }

    return deck;
}

void Initialization(int** user, int** dealer, int* deck) {
    *user = (int*)malloc(sizeof(int) * 2);
    *dealer = (int*)malloc(sizeof(int) * 2);

    (*user)[0] = deck[0];
    (*dealer)[0] = deck[1];
    (*user)[1] = deck[2];
    (*dealer)[1] = deck[3];
}


int status(int* User, int* Dealer, int user_cnt, int dealer_cnt) {
    char cards[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K' };

    int dealer_sum = card_sum(Dealer, dealer_cnt);
    int user_sum = card_sum(User, user_cnt);

    printf("Dealer : ");
    for (int i = 0; i < dealer_cnt; i++) {
        if (cards[Dealer[i] - 1] == 'X')
            printf("10 ");
        else
            printf("%c ", cards[Dealer[i] - 1]);
    }
    printf("\n");
    //printf("size of user : %d\n", sizeof(User));
    printf("User : ");
    for (int i = 0; i < user_cnt; i++) {
        if (cards[User[i] - 1] == 'X')
            printf("10 ");
        else
            printf("%c ", cards[User[i] - 1]);
    }
    printf("\n");

    if (user_sum > 21) //user Bursted
        return 1;
    else if (dealer_sum > 21) //Dealer Bursted
        return 2;
    else if (user_sum == 21)
        return 3;
    else if (dealer_sum == 21)
        return 4;
    else
        return 0;
}


int* Hit(int** user, int* deck, int idx, int user_cnt) {

    int* temp = NULL;

    temp = realloc(*user, sizeof(int) * (user_cnt + 1));

    if (temp != NULL)
        user = temp;

    temp[user_cnt] = deck[idx];

    return temp;
}

int* End(int** dealer, int* deck, int idx, int dealer_cnt) {

    int dealer_sum = card_sum(*dealer, dealer_cnt);
    int* temp = NULL;

    printf("Dealer Sum(End) : %d\n", dealer_sum);
    temp = (int*)realloc(*dealer, sizeof(int) * (dealer_cnt + 1));
    if (temp != NULL)
        dealer = temp;
    temp[dealer_cnt] = deck[idx];

    return temp;
}

void Result(int* user, int* dealer, int user_cnt, int dealer_cnt) {
    int user_sum = card_sum(user, user_cnt);
    int dealer_sum = card_sum(dealer, dealer_cnt);

    if (user_sum > dealer_sum)
        printf("User Wins! Congratulation!\n");
    else if (user_sum < dealer_sum)
        printf("User Lose. Dealer Wins\n");
    else
        printf("Draw!\n");

    free(user);
    free(dealer);
}

int card_sum(int* card, int card_cnt) {

    int sum = 0;

    for (int i = 0; i < card_cnt; i++) {
        if (card[i] - 1 >= 10)
            sum += 10;
        else
            sum += card[i];
    }
    //printf("Card Sum : %d\n", sum);

    return sum;
}