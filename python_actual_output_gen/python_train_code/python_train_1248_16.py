n=int(input())
a=list(map(int,input().split()))
l=sum(a)//2
ans=0
for i in range(n):
    ans+=a[i]
    if ans>=l:
        print(i+1)
        break
    
