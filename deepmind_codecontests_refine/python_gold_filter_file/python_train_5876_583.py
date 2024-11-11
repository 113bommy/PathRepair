n = input()
p = input()
q = list(p)
q.reverse()
if list(n) == q:
    print("YES")
else:
    print("NO")
