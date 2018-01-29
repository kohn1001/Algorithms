from collections import Set

"""

Illustrating the boxes, given i,j get the box:

     012 345 678
    |___|___|___|
   0|   |   |   |
   1| 0 | 1 | 2 |
   2|___|___|___|
   3|   |   |   |
   4| 3 | 4 | 5 |
   5|___|___|___|
   6|   |   |   |
   7| 6 | 7 | 8 |
   8|___|___|___|

"""

class Sudoku:
    def __init__(self, mat):
        self.mat = mat
        self.used_col = [set() for _ in range(len(self.mat[0]))]
        self.used_row = [set() for _ in range(len(self.mat))]
        self.used_box = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if self.mat[i][j] != 0:
                    val = self.mat[i][j]
                    self.used_row[i].add(val)
                    self.used_col[j].add(val)
                    self.used_box[self.get_box_idx(i,j)].add(val)

    def get_next_cell(self):
        for i in range(9):
            for j in range(9):
                    if self.mat[i][j] == 0:
                        return i,j
        return -1, -1

    @staticmethod
    def get_box_idx(i, j):
        """
            00,01,02->0; 03,04,05->1; 06,07,08->2;
            10,11,12->0; 13,14,15->1; 16,17,18->2;
            20,21,22->0; 13,14,15->1; 16,17,18->2;
            30,31,32->3; 33,34,35->4; 36,37,38->5
        """
        return (i/3)*3 +j/3

    def is_valid(self, i, j, k):
        if k in self.used_box[self.get_box_idx(i,j)] or k in self.used_row[i] or k in self.used_col[j]:
            return False
        #if k in self.used_row[i] or k in self.used_col[j]:
        return True

    def mark_box(self, i, j, k, used):
        if used:
            self.mat[i][j] = k
            self.used_row[i].add(k)
            self.used_col[j].add(k)
            self.used_box[self.get_box_idx(i,j)].add(k)
        else:
            self.used_row[i].remove(k)
            self.used_col[j].remove(k)
            self.used_box[self.get_box_idx(i,j)].remove(k)
            self.mat[i][j] = 0

    def solve(self):
        i, j = self.get_next_cell()
        #self.print_sudoku()
        #print ('free i: {}, free j: {}'.format(i,j))
        if i== -1 and j == -1:
            return True
        else:
            for k in range(1, 10):
                if self.is_valid(i,j,k): 
                    self.mark_box(i,j,k, True)
                    if self.solve():
                        return True
                    else:
                        self.mark_box(i,j,k, False)
                    #mark un used
        return False
    
    def print_sudoku(self):
        print('\n')
        for i in range(0, 9):
            print (self.mat[i])


if __name__ == '__main__':
    mat = [ [0, 6, 0, 0, 0, 5, 2, 0, 4],
            [0, 2, 0, 0, 1, 6, 0 ,0, 3],
            [0, 5, 3, 0, 0, 4, 0, 0, 0],
            [2, 0, 0, 0, 7, 1, 9, 0, 8],
            [1, 0, 0, 9, 0, 0, 7, 4, 0],
            [4, 0, 9, 0, 6, 0, 0, 0, 0],
            [0, 1, 2, 6, 0, 0, 8, 0, 9],
            [0, 4, 7, 8, 2, 0, 1, 0, 5],
            [0, 0, 0, 0, 5, 0, 4, 0, 0] ]

    sod = Sudoku(mat)
    sod.print_sudoku()
    sod.solve()
    sod.print_sudoku()
