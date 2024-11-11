a = [0]*5001
n = int(input())
x = list(map(int, input().split()))
for i in x:
    a[i] += 1
ans = 0
for i in range(5001):
    ans += max(0, a[i]-1)
    if i > n and a[i] > 0:
        ans +=1
print(ans)