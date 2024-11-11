n=int(input())
ar=list(map(int,input().split()))
def f(i):
    ans=0
    for e in ar:
        if(e==i):continue
        else:ans+=abs(e-i)-1
    return ans
a=float('inf')
b=0
for x in range(1,1001):
    if(f(x)<a):
        a=f(x)
        b=x
print(b,a)