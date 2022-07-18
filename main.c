#include <stdio.h>
#include <string.h>

char board[] = "_________";
char current_player = 'X';
int play_count = 0;
char winner = '_';

void print_board();
void check_win_state();
void take_turn();
void reset_game();
char ask_play_again();
void handle_win_state();
void play();
void change_player();

void change_player() {
  if (play_count % 2 == 0) {
    current_player = 'X';
  } else {
    current_player = 'O';
  }
}

void print_board() {
  printf("\n=====\nCurrent Player: %c\n=====\n", current_player);
  
  for (int i = 0; i < 9; i++) {
    if (i > 0 && i % 3 == 0) {
      printf("\n");
    }
    printf("%c", board[i]);
  }
  printf("\n");
}

int get_char_index(int row, int col) {
  int position = ((3 * row) - 3) + col;
  return position - 1;
}

void check_win_state() {
  // TODO - condense with an algorithm or for loop
  // win states: 012 345 678 036 147 258 048 246
  if (board[0] == current_player && board[1] == current_player && board[2] == current_player) {
    winner = current_player;
  } else if (board[3] == current_player && board[4] == current_player && board[5] == current_player) {
    winner = current_player;
  } else if (board[6] == current_player && board[7] == current_player && board[8] == current_player) {
    winner = current_player;
  } else if (board[0] == current_player && board[3] == current_player && board[6] == current_player) {
    winner = current_player;
  } else if (board[1] == current_player && board[4] == current_player && board[7] == current_player) {
    winner = current_player;
  } else if (board[2] == current_player && board[5] == current_player && board[8] == current_player) {
    winner = current_player;
  } else if (board[0] == current_player && board[4] == current_player && board[8] == current_player) {
    winner = current_player;
  } else if (board[2] == current_player && board[4] == current_player && board[6] == current_player) {
    winner = current_player;
  }
}

void take_turn() {
  int row, col;

  printf("\nEnter your row: ");
  scanf("%i", &row);
  printf("\nEnter your column: ");
  scanf("%i", &col);

  int index_to_update = get_char_index(row, col);

  if (board[index_to_update] == '_') {

    board[index_to_update] = current_player;
    play_count = play_count + 1;

    print_board();
    check_win_state();
    change_player();
  } else {
    printf("\nNot available, try again");
    take_turn();
  }
}

void reset_game() {
  strcpy(board, "_________");
  current_player = 'X';
  play_count = 0;
  winner = '_';
  play();
}

char ask_play_again() {
  int play_again;
  printf("Play Again? (1 = Yes, 0 - No): ");
  scanf("%i", &play_again);

  return play_again;
}

void handle_win_state() {
  printf("********\n%c Wins!\n********\n", winner);
    
  int response = ask_play_again();

  if (response == 1) {
    reset_game();
  } else {
    printf("Thanks for playing!\n");
  }
}

void play() {
  if (play_count < 9 && winner == '_') {
    print_board();
    take_turn();
    play();
  } else if (play_count == '9' && winner == '_') {
    printf("Tie Game!");
  } else {
    handle_win_state();
  }
}

int main() {
  play();

  return 0;
}