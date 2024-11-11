q = int(input())

for _ in range(q):
    s = set(input())
    t = set(input())
    if s == t:
        print("YES")
    else:
        print("NO")
