n = int(input())
s = set()
s1 = set()
for i in range(n**2):
    a, b = map(int, input().split())
    if a not in s and b not in s:
        s.add(a)
        s1.add(b)
        print(i + 1)
    