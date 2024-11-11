x,n=map(int,input().split())
p=list(map(int,input().split()))
p.sort()
ans=100
for i in range(101):
    if p.count(i)==0:
        if abs(ans-x)>abs(i-x):
            ans=i
print(ans) 

