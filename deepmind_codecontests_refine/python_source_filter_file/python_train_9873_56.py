n, a, b = map(int, input().split())
cnt = 0
for i in range(1, N+1):
    if a <= sum(list(map(int, str(i)))) <= b:
        cnt += i
print(cnt)