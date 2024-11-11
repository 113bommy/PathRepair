import fractions

N=int(input())
t,a=1,1
for i in range(N):
    T,A=map(int,input().split())
    # n=max(-(-a//A),-(-t//T))
    n=max(fractions.ceil(a/A),fractions.ceil(t/T))
    t,a=n*T,n*A

print(t+a)
