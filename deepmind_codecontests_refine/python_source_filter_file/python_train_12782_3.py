n=int(input())
a=list(map(int,input().split()))
ans=0
b=[0]*n
for i in range(n):
    b[a[i]]+=1
for k in b:
    ans+=k*(k-1)//2
for i in range(n):
    print(ans-b[a[i]]+1)