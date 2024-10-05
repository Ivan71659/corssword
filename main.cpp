#include <iostream>
#include <vector>

using namespace std;

vector <vector <string>> board;

void check_direction (string ask1) {
  if(ask1 != "across" && ask1 != "down"){
    throw logic_error ("you cannot move that way");
  }
}

void check_colour (string ask1, string ask2) {
  if(ask1 == "across" && ask2 != "green" && ask2 != "purple" && ask2 != "orange"){
    throw logic_error ("no no ur wrong");
  } else if(ask1 == "down" && ask2 != "red" && ask2 != "yellow" && ask2 != "blue"){
    throw logic_error ("no no ur wrong");
  }
}

void check_word (string ask1, string ask2, string ask3) {
  if(ask1 == "across" && ask2 == "green" && ask3 != "watermelon") {
    throw logic_error ("no no ur wrong");
  } else if(ask1 == "across" && ask2 == "green" && ask3 == "watermelon") {
    board [2][1] = "🟩";
    board [2][2] = "🟩";
    board [2][3] = "🟩";
    board [2][4] = "🟩";
    board [2][5] = "🟩";
    board [2][6] = "🟩";
    board [2][7] = "🟩";
    board [2][9] = "🟩";
  }
  
  if(ask1 == "across" && ask2 == "purple" && ask3 != "banana") {
    throw logic_error ("no no ur wrong");
  }
  else if(ask1 == "across" && ask2 == "purple" && ask3 == "banana"){
    board [5][5] = "🟪";
    board [5][6] = "🟪";
    board [5][7] = "🟪";
    board [5][8] = "🟪";
    board [5][9] = "🟪";
  }
  
  if(ask1 == "across" && ask2 == "orange" && ask3 != "apple") {
    throw logic_error ("no no ur wrong");
  }
  else if(ask1 == "across" && ask2 == "orange" && ask3 == "apple"){
    board [6][1] = "🟧";
    board [6][2] = "🟧";
    board [6][3] = "🟧";
    board [6][4] = "🟧";
  }
  
  if(ask1 == "down" && ask2 == "red" && ask3 != "grape") {
    throw logic_error ("no no ur wrong");
  }
  else if (ask1 == "down" && ask2 == "red" && ask3 == "grape") {
    board [1][1] = "🟥";
    board [2][1] = "🟥";
    board [3][1] = "🟥";
    board [4][1] = "🟥";
  }
  
  if(ask1 == "down" && ask2 == "blue" && ask3 != "strawberry") {
    throw logic_error ("no no ur wrong");
  }
  else if(ask1 == "down" && ask2 == "blue" && ask3 == "strawberry") {
    board [1][4] = "🟦";
    board [2][4] = "🟦";
    board [3][4] = "🟦";
    board [4][4] = "🟦";
    board [6][4] = "🟦";
    board [7][4] = "🟦";
    board [8][4] = "🟦";
    board [9][4] = "🟦";
  }
  
  if(ask1 == "down" && ask2 == "yellow" && ask3 != "orange") {
    throw logic_error ("no no ur wrong");
  }
  else if(ask1 == "down" && ask2 == "yellow" && ask3 == "orange"){
    board [3][8] = "🟨";
    board [4][8] = "🟨";
    board [5][8] = "🟨";
    board [6][8] = "🟨";
    board [7][8] = "🟨";
  }
}

bool check_win () {
  int counter = 0;
  
  for (int i = 0; i < board.size (); i++) {
    vector <string> row = board [i];
    for (int j = 0; j < row.size (); j++) {
      string column = row [j];
      if(column == "⬜"){
        counter += 1;
      }
    }
  }
  
  if(counter == 0){
    return true;
  }
  return false;
}

int main () { 
  board = {
    {"⬛","🟥","⬛","⬛","🟦","⬛","⬛","⬛","⬛","⬛",},
    {"⬛","⬜","⬛","⬛","⬜","⬛","⬛","⬛","⬛","⬛",},
    {"🟩","⬜","⬜","⬜","⬜","⬜","⬜","⬜","🟨","⬜",},
    {"⬛","⬜","⬛","⬛","⬜","⬛","⬛","⬛","⬜","⬛",},
    {"⬛","⬜","⬛","⬛","⬜","⬛","⬛","⬛","⬜","⬛",},
    {"⬛","⬛","⬛","⬛","🟪","⬜","⬜","⬜","⬜","⬜",},
    {"🟧","⬜","⬜","⬜","⬜","⬛","⬛","⬛","⬜","⬛",},
    {"⬛","⬛","⬛","⬛","⬜","⬛","⬛","⬛","⬜","⬛",},
    {"⬛","⬛","⬛","⬛","⬜","⬛","⬛","⬛","⬛","⬛",},
    {"⬛","⬛","⬛","⬛","⬜","⬛","⬛","⬛","⬛","⬛",},
  };
  while(true){
    cout << "\n";
    for (int i = 0; i < board.size ( ); i++) {
      for (int j = 0; j < board.size (); j++) {
        cout << board [i][j];
      }
      cout << "\n";
    }

    if(check_win() == true){
      break;
    }
  
    cout << "\nAcross\n🟩 A big fruit you eat in the summer\n🟪 Fruit that monkeys like\n🟧 A red fruit\n\nDown\n🟥 Purple fruit\n🟦 A small red fruit\n🟨 ______ juice\n\n";
    
    string ask1;
    cout << "which direction do you wanna move? ";
    cin >> ask1;
    
    try { 
      check_direction (ask1);
      
      string ask2;
      cout << "what color u chose? ";
      cin >> ask2;
  
      try{
        check_colour (ask1,ask2);
        
        string ask3;
        cout << "what is ur answer? ";
        cin >> ask3;
  
        try { 
          check_word (ask1, ask2, ask3);
        } catch (logic_error e) {
          cout << e.what () << "\n";
        }
       
      } catch (logic_error e) {
        cout << e.what () << "\n";
      }
    
    } catch (logic_error e) {
      cout << e.what () << "\n";
    }
  }
  
}
