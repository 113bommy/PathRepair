n, x, y = list(map(int, input().split()))
l = list(input())
cnt = 0
for i in range(n - 1, n - x , -1):
    if l[i] == '1' and n - y - 1 != i:
        cnt+= 1
    if n - y - 1 == i and l[i] == '0':
        cnt += 1
print(cnt)