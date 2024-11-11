n = int(input())
s = input()
s1 = input()
ans = 0
for i in range(n):
    a, b = int(s[i]), int(s1[i])
    ans += min(abs(a - b), 10 - abs(a - b))
    print(ans)