n = int(input())
a = list(map(int,input().split()))
X = sum(a)
ans = 10*50
x = 0
for i in range(n-1):
    x +=a[i]
    ans = min(ans,abs(X-2*x))
print(ans)
    
