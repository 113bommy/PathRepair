import math
import collections


def cint() : return list(map(int, input().split())) 
def cstr() : return list(map(str, input().split(' '))) 

def solve():
    matrix  = []
    for _ in range(3): matrix.append(cint())
    # print(matrix)

    for i in range(1,10**5):
        col1 =  i + matrix[1][0] + matrix[2][0]
        y = col1 - matrix[1][0] - matrix[1][2] 
        z = col1 - matrix[2][0] - matrix[2][1]

        if y>0 and z>0 and i+y+z==col1:
            matrix[0][0] = i
            matrix[1][1] = y
            matrix[2][2] = z
            for row in matrix:
                for j in row:
                    print(j, end=' ')
                print('')
            return
    
    return


   



        
    

   
if __name__ == "__main__":
    # t = int(input())
    t = 1
    while t!=0:
        solve()
        t-=1