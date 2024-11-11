n,m = list(map(int,input().split()))
x = list(map(int,input().split()))
y = list(map(int,input().split()))
a = 0
b = 0
Mod = 10**9 + 7

for k in range(1,n+1):
    a += (k-1)*x[k-1] - (n-k)*x[k-1]
for j in range(1,m+1):
    b += (j-1)*y[j-1] - (m-j)*y[j-1]

res = a*b
print(a*b%Mod)