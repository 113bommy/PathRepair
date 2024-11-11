N=int(input())
a=list(map(int,input().split()))
S=sum(a)
s=2*a[0]
d=abs(S-2*a[0])
for i in range(1,N-1):
    s+=2*a[i]
    d=min(d,abs(S-s))
print(d)