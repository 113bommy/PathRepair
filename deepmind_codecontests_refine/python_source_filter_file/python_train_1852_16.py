n,x,y= map(int, input().split())

ans=[0]*n

for i in range(1,n):
    for j in range(i+1,n+1):
        ans[min(j-i,1+abs(i-x)+abs(j-y))-1]+=1

for i in range(n):
    print(ans[i])