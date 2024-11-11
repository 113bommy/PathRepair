mo=10**9+7
n,m=map(int,input().split())
x=[int(i) for i in input().split()]
y=[int(i) for i in input().split()]
X,Y=0,0
for i in range(n):
    X+=x[i]*(n-2*i-1)
    X%=mo
for i in range(m):
    Y+=y[i]*(m-2*i-1)
    Y%=mo
print(X*Y%mo)