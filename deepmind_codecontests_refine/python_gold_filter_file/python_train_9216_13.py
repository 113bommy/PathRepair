n,a,b,c,d=tuple(map(int,input().split()))
ans=0
sum=0
def ch(c):
    return (n>=c and c>0)

for i in range(1,n+1):
    sum=i+a+b
    x2=sum-a-c
    x3=sum-c-d
    x4=sum-b-d
    if ch(i) and ch(x2) and ch(x3) and ch(x4):
        ans+=1

print(ans*n)