s = list(map(int, input()))
t = list(map(int, input()))
n = len(s)

if len(s) != len(t) or 1 not in s or 1 not in t:
    print("NO")
else:
    print("YES")