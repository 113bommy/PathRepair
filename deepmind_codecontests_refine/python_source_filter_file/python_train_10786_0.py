n=int(input())
a = [0]*(n+1)
for i in range(n-1):
    for i in input().split():
        a[int(i)]+=1
l = a.count(1)
print ((l*2**(n-l+1)+(n-l)*(2**(n-l)))%(1e9+7))