H=list(map(int,input().split()))
n=H[0]
m=H[1]
k=H[2]
a=1
b=1
c=1
for i in range (1,n):
    a=a*i
for i in range (1,n-k):
    b=b*i
for i in range (1,k+1):
    c=c*i




q=a//(b*c)
ans=q*m*(m-1)**(k)
print(ans%988244353)