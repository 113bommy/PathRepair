n = int(input())

s = list(map(int, input().split()))
for i in range(n):
    s[i] = s[i] % 2

print(s.index(s.count(1) if 1 < s.count(0) else 0))