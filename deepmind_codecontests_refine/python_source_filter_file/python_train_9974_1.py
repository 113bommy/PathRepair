from fractions import*
N,*A=map(int,open(0).read().split())
w,B=0,[0]
a=range(N)
for x in a[:]:B+=[gcd(B[-1],A[x])]
w=M=0
for x in a[::-1]:M,w=max(M,gcd(w,B.pop())),gcd(w,A[x])
print(M)