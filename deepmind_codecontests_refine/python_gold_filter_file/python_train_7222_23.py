matrix = [[] for i in range(4)]
for i in range(4):
    matrix[i] = input()
    
    
def test(matrix):
    for i in range(3):
        for j in range(3):
            counter = 0
            if matrix[i][j] == matrix[i][j+1]: counter += 1
            if matrix[i][j] == matrix[i+1][j]: counter += 1
            if matrix[i][j] == matrix[i+1][j+1]: counter +=1
            if counter != 1: 
                    return True;
    return False

print("YES" if test(matrix) else "NO")