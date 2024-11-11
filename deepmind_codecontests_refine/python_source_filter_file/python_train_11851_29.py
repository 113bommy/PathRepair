def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a

n=int(input())
ans=[0]*n
k=0
i=2
while k<n-1:
    if i%2==0 or i%3==0:
        ans[k]=i
        k+=1
    i+=1
x=sum(ans)
ans[-1]=30000-6+(x+5)//6*6-x
while gcd(ans[-1],x)==1:
    ans[-1]-=6
print(*ans)