n=int(input())
a = list(map(int,input().split()))
a0 = [0] * (n//2+1)
a1 = [0] * (n//2+1)
for i in range(n//2):
    a0[i+1] = a0[i] + a[i*2]
if n% 2 != 0:
    a0.append(a0[-1] + a[-1])

max_even = [0] * (n//2+1)
for i in range(n//2):
    max_even[i+1] = max(max_even[i]+a[2*i+1], a0[i+1])

ans = -1e9*n
if n%2 == 0:
    ans = max_even[-1]
else:
    for i in range(0,n//2+1):
        ans = max(ans, max_even[i] + a0[-1] - a0[i+1])
print(ans)