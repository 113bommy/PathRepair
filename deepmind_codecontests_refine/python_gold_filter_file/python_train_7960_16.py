d = {2: '2', 3: '3', 4: '322', 5: '5', 6: '53', 7: '7', 8: '7222', 9: '7332'}
n = int(input())
x = list(map(int, input()))
ans = []
for i in range(n):
    if x[i] in d:
        ans += d[x[i]]
ans.sort(reverse=True)
print(*ans, sep='')
