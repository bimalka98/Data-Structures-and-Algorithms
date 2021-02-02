// Declaring functions

int up(vector<string> &grid, int& currentX, int& currentY){ // Function to move upward in the grid
  int count = 0;
  while((currentX < grid.size()-1)){
    if(grid[currentX+1][currentY] == '.'){ // Loop continuous as long as the current path  is clear.
      grid[currentX][currentY] = 'X'; //Replace current position with 'X' in order to make sure there is no going back along the same way.
      currentX++;
      count++;
    }
    else break;
  }
  return (count >0);// Several Steps along the same direction considered as a single move. If there is at least one count, it is a valid move.
}
int down(vector<string> &grid, int& currentX, int& currentY){ // Function to move downward in the grid
  int count = 0;
  while((currentX >0)){
    if (grid[currentX-1][currentY] == '.'){ // Loop continuous as long as the current path  is clear.
      grid[currentX][currentY] = 'X'; //Replace current position with 'X' in order to make sure there is no going back along the same way.
      currentX--;
      count++;
    }
    else break;
  }
  return (count >0); // Several Steps along the same direction considered as a single move. If there is at least one count, it is a valid move.
}
int right(vector<string> &grid, int& currentX, int& currentY){ // Function to move right in the grid
  int count = 0;
  while((currentY < grid.size()-1)){
    if (grid[currentX][currentY+1] == '.'){ // Loop continuous as long as the current path  is clear.
      grid[currentX][currentY] = 'X'; //Replace current position with 'X' in order to make sure there is no going back along the same way.
      currentY++;
      count++;
    }
    else break;
  }
  return (count >0); // Several Steps along the same direction considered as a single move. If there is at least one count, it is a valid move.
}
int left(vector<string> &grid, int& currentX, int& currentY){ // Function to move left in the grid
  int count = 0;
  while((currentY >0)){
    if (grid[currentX][currentY-1] == '.'){ // Loop continuous as long as the current path is clear.
      grid[currentX][currentY] = 'X'; //Replace current position with 'X' in order to make sure there is no going back along the same way.
      currentY--;
      count++;
    }
    else break;
  }
    return (count >0); // Several Steps along the same direction considered as a single move. If there is at least one count, it is a valid move.
}

int minimumMoves(vector<string> &grid, int startX, int startY, int goalX, int goalY) {
int moves = 0;
int currentX = startX;
int currentY = startY;
while((currentX != goalX) || (currentY !=goalY)){ // Finding paths until we reach the tartget position.
    // Consider every possible move that can be taken at a given position.
    moves += up(grid, currentX, currentY);
    moves += left(grid, currentX, currentY);
    moves += down(grid, currentX, currentY);
    moves += right(grid, currentX, currentY);
}
return moves;
}
