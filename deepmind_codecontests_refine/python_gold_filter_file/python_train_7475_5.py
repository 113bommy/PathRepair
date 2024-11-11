n, q = map(int, input().split())
s = input()
t = [0] * n
for i in range(1, n):
    t[i] = t[i - 1] + (1 if s[i - 1:i + 1] == "AC" else 0)
for i in range(q):
    l, r = map(int, input().split())
    print(t[r - 1] - t[l - 1])