n,a=map(int,input().split())
x=180/n
min=10000000
angle=0
for i in range(n-2) :
    angle+=x
    if min>abs(angle-a) :
        min=abs(angle-a)
        ans=i
print(1,2,ans+3)