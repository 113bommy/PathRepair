n = int(input())
a = input()
ans = [0 for i in range(n)]
k = 0
for i in range(1, n):
    if a[i] == '(':
        ans[i] = k + 1
        k += 1
    else:
        ans[i] = k
        k -= 1
for x in ans:
    print(x % 2, end = ' ')
