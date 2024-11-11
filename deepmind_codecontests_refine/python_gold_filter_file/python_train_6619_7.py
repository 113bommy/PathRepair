n = int(input())
mas = list(map(int, input().split()))
check = [0 for i in range(n)]
ch = 0
ans = 0
for i in range(2 * n):
    check[mas[i] - 1] += 1
    if check[mas[i] - 1] == 2:
        ch -= 1
    else:
        ch += 1
    ans = max(ans, ch)
print(ans)