n = int(input())
t = list(map(int, input().split()))
a = list(map(int, input().split()))
mod = 10**9+7
ans = 1
if n == 1 and t != a:
    print(0)
    exit()
for i in range(1,n-1):
    if t[i-1] == t[i] and a[i] == a[i+1]:
        ans = (ans*min(t[i],a[i]))%mod
    elif t[i-1] < t[i] and t[i] > a[i]:
        print(0)
        exit()
    elif a[i] > a[i+1] and t[i] < a[i]:
        print(0)
        exit()
print(ans)
