n=int(input())
x=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
    for j in range(n):
        if i!=j and i!=n-j and i+1!=(n-1)//2 and j+1!=(n-1)//2:
            x[i][j]=0
print(sum([sum(i) for i in x]))