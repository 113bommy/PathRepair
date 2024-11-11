N, M = map(int, input().split())
num = [0] * (N+1)
for i in range(M):
    a, b = map(int, input().split())
    num[a] += 1
    num[b] += 1

flag = 1
for i in num:
    if num % 2 != 0:
        flag = 0

if flag = 1:
    print("YES")
else:
    print("NO")
