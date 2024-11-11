S = input()
Q = int(input())

d = 0
X = [[], []]
for i in range(Q):
    q = input()
    if q[0] == "1":
        d = (d + 1) % 2
    else:
        a, f, c = q.split()
        x = (int(f) + d) % 2
        X[x].append(c)

if d == 0:
    v = "".join(X[1])[::-1] + S + "".join(X[0])
else:
    v = "".join(X[0])[::-1] + S[::-1] + "".join(X[1])
print(v)
