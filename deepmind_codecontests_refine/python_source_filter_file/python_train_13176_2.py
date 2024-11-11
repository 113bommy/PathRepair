n, m = map(int, input().split())

s1 = set()
for _ in range(n):
    s1.add(input())

s2 = set()
for _ in range(m):
    s2.add(input())

nm = len(s1 & s2)

if n + (1 if nm%2==0 else 0) > m:
    print('YES')
else:
    print('NO')