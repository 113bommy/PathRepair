n, q = map(int, input().split())
s = input()
ac = [0] * (n + 1)
for i in [0] * n:
    ac[i + 1] = ac[i] + (1 if s[i:i + 2] == "AC" else 0)
for i in [0] * q:
    l, r = map(int, input().split())
    print(ac[r-1] - ac[l-1])