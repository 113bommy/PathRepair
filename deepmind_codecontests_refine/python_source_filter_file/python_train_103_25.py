c={
    'S':[1]*13,
    'H':[1]*13,
    'C':[1]*13,
    'D':[1]*13
}
n=int(input())
for i in range(n):
    a,b=input().split
    c[a][int(b)-1]=0
for i in ['S','H','C','D']:
    for j in range(13):
        if c[i][j]==1:
            print(i,j+1)


