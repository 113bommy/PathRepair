n = list(input())
d = int(input())
if len(n) < d:
    print("impossible")
else:
    print(max(0, d - len(set(n))))
