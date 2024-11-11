n,m = map(int,input().split())
s=0
a = n*(n-1)/2
nHalf = n//2
b = nHalf**2
if n%2:
    b+=nHalf
for i in range(m):
    x,y = map(int,input().split())
    s+=n*x
    s+=y*(a if y>0 else b)
print(s/n)
