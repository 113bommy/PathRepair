
from collections import deque
n , m , c = input().split()
n = int(n)
m = int(m)
matrix = deque()
for i in range(n):
    matrix.append(list(input()))
st = set()
def isvalid(i , j ):
    return i >= 0 and j >0 and i < n and j < n and matrix[i][j] != '.' and matrix[i][j] != c

cnt = 0
for i in range(n):
    for j in range(m):
        if matrix[i][j] == c :
            if isvalid(i - 1 , j ):
                st.add(matrix[i - 1][j])

            if isvalid(i + 1 , j):
                st.add(matrix[i + 1][j])

            if isvalid(i , j + 1):
                st.add(matrix[i][j + 1])

            if isvalid(i , j - 1):
                st.add(matrix[i][j - 1])

#print(st)
print(len(st))

