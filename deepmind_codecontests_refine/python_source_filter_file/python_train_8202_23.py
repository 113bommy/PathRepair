N = int(input())

ans = 0

for i in range(1, N):
    x =  (N - i) // i
    if x < i:
        break
    if (N - i) % i == 0:
        ans += x

print(ans)



