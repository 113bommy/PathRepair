n=int(input())
a=[int(x) for x in input().split()]
x=1
ans=0
for i in a:
    ans+=abs(x-i)
    x+=2
ans1=0
y=2
for i in a:
    ans1+=abs(y-i)
    y+=2
print(min(ans,ans1))
    
