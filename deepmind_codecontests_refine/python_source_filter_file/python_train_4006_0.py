n,m,k=map(int,input().split())
mx=[[0]*(m+2) for x in range(n+2)]

def square_check(i,j):
    if mx[i][j+1] and mx[i+1][j] and mx[i+1][j+1]:
        return True
    if mx[i][j-1] and mx[i+1][j] and mx[i+1][j-1]:
        return True
    if mx[i-1][j+1] and mx[i-1][j] and mx[i-1][j+1]:
        return True
    if mx[i-1][j-1] and mx[i-1][j] and mx[i][j-1]:
        return True
    return False
num=0
for i in range(k):
    x,y=map(int,input().split())
    mx[x][y]=1
    if square_check(x,y):
        num=i+1
        break
print(num)