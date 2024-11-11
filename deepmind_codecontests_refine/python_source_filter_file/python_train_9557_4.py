n=int(input())
p,r=print,range
if n&-n==n:p("No");exit(0)
p("Yes")
if n==3:p(1,2);p(2,3);p(3,4);p(4,5);p(5,6);exit(0)
k=1
while k*2<n:k*=2
for i in r(k+2):p(i+1,i+2)
p(k-1,n+1)
for i in r(k+2):p(n+i+1,n+i+2)
p(n+k,n+1);p(n+k+1,k)
for i in r(n-k):p(n+i+1,n+k+i+1);p(n+k+i,k+i+1)