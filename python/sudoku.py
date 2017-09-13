from collections import Set


class Sovle_suduko:
    def __init__(self, N, M, box_size):
        self.N = N
        self.M = M
        self.box_size = box_size
        self.board = [ [-1 for i in range(M)] for j in range(N)]
    
    def is_valid(self, num, row, col):
        for i in range(row):
            if self.board[i][col] == num:
                return False
        for i in range(col):
            if self.board[row][i] == num:
                return False
        if not self.valid_in_box(row-row%self.box_size, col-col%self.box_size, num):
            return False
        return True
    
    
    def valid_in_box(self, base_row, base_col, num):
        for i in range(self.box_size):
            for j in range(self.box_size):
                if self.board[base_row+i][base_col+j] == num:
                    return False
        return True
    
    def print_board(self):
        for i in range(self.N):
            print(self.board[i])
            
    def get_free_cell(self):
        for i in range(self.N):
            for j in range(self.M):
                if self.board[i][j] == -1:
                    return i, j
        return -1, -1
        
    def find_sol(self):
        if self.solved():
            return True
        row, col = self.get_free_cell()

        for num in range(1, 10):
            if self.is_valid(num, row, col):
                self.board[row][col] = num
                if self.find_sol():
                    return True
                self.board[row][col] = -1
        return False
    
    
    def solved(self):
        i, j = self.get_free_cell()
        if i == -1 and j == -1: return True
        return False
             


soduko = Sovle_suduko(9, 9, 3)
soduko.find_sol()
soduko.print_board()

