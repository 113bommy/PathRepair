n=int(input())
x=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
    for j in range(n):
        if i!=j and i!=n-j-1 and i!=(n-1)//2 and j!=(n-1)//2:
            x[i][j]=0
print(sum([sum(i) for i in x]))