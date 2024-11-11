n = int(input())
ans = []
tmp = n
for i in range(min(n, 3163), 0, -1):
    if tmp > i * (i - 1) // 2:
        ans.append(i)
        tmp -= i
ans.sort()
print('\n'.join(map(str, ans)))
