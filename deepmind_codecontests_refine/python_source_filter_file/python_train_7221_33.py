n=5
l=[]
k=1
for i in range(n):
    l+=[list(map(int,input().split()))]
for i in range(n):
    for j in range(n):
        if l[i][j]==1:
            print(abs(i-3)+abs(j-3))
            k=1