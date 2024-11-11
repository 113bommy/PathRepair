from sys import stdin
t = int(stdin.readline())
for _ in range(t):
    a, b = map(int, stdin.readline().split())
    ans = []
    tot = a + b
    x = tot // 2
    s = tot - x
    for i in range(min(x, a)+1):
        if a-i <= s:
            ans.append(a-i+x-i)
    for i in range(min(a, s)+1):
        if a-i <= x:
            ans.append(a-i+s-i)
    print(len(set(ans)))
    print(*list(set(ans)))
    