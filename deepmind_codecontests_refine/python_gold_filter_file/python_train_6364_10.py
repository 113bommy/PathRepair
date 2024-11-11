n=int(input())
a=list(map(int,input().split()))
t=sum(a)//n
ini=max(1,t-43)
fi=min(100, t+43)
temp=0
ans=10000000000
for i in range(ini,fi+1):
    temans=0
    for j in range(n):
        if abs(i-a[j]) >1:
            temans+=abs(i-a[j])-1
    if temans<ans:
        ans=temans
        temp=i
print(temp,ans)
        
        