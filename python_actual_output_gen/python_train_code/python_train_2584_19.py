n, q = map(int, input().split())
s = input()
x = []*(n+1)

for i in range(n):
    x[i+1] = x[i] + (1 if s[i:i+2] == "AC" else 0)

for i in range(q):
    l, r = map(int, input().split())
    print(x[r-1] - x[l-1])