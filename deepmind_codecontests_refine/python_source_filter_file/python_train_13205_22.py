import math

N,A,B=map(int,input().split())

v=list(map(int,input().split()))
v.sort(reverse=True)
print(sum(v[0:A])/A)

cnt=v.count(v[0])
cnt2=v.count(v[A-1])
V=v[0:A]
cnt3=V.count(v[A-1])

def combinations_count(n, r):
        return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
        
if cnt<A:
    print(combinations_count(cnt2, cnt3))
elif cnt==A:
    print(1)
elif cnt>A:
    ans=0
    for i in range(A,min(cnt,B)):
        ans+=combinations_count(cnt,i)
    print(ans)
