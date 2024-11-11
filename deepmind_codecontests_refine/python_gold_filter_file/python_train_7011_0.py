n, m = list(map(int, input().split()))
answer = 0

for a in range(max(n, m) + 1):
    for b in range(max(n, m) + 1):
        if a**2 + b is n and a + b**2 is m:
            answer += 1

print(answer)
