n = int(input())
#n, m = map(int, input().split())
s = input()
c = list(map(int, input().split()))
l = 10 ** 10
for i in range(1, n):
    if s[i] == 'L' and s[i - 1] == 'R':
        l = min(l, c[i] - c[i - 1])
if l == 10 * 10:
    print(-1)
else:
    print(l // 2)