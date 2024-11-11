n = list(input())
d = int(input())
if len(n) < d:
    print("impossible")
else:
    print(d - len(set(n)))
