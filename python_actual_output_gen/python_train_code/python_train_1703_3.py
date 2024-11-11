n, s, t = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
    if s == t:
        print(i)
        quit()
    s = a[s -1]

print(i)