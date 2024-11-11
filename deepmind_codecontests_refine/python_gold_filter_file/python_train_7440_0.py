n = int(input())

g = {}

ins = {}
outs = {}
vs = set()

for _ in range(n):
    s = input().strip()

    left = s[:-1]
    right = s[1:]

    g.setdefault(left, []).append(right)

    outs[left] = outs.get(left, 0) + 1
    ins[right] = ins.get(right, 0) + 1
    vs.add(left)
    vs.add(right)

# print(g)
# print(outs)
# print(ins)
wrong = []

for v in vs:
    # print(v, outs.get(v, 0), ins.get(v, 0))
    if outs.get(v, 0) != ins.get(v, 0):
        wrong.append(v)

# print(wrong)
if len(wrong) not in (0, 2):
    print("NO")
    exit()


if wrong:
    a, b = wrong
    if abs(ins.get(a, 0) - outs.get(a, 0)) != 1 or abs(ins.get(b, 0) - outs.get(b, 0)) != 1:
        print("NO")
        exit()
    if ins.get(a, 0) < outs.get(a, 0):
        a, b = b, a

    stack = [a, b]
else:
    stack = [next(iter(g))]

ans = []

while stack:
    v = stack[-1]
    # print("ON STACK", v)
    if not g.get(v, []):
        if ans:
            ans.append(v[0])
        else:
            ans.append(v)
        # print("TO ANS", v)
        stack.pop(-1)
    else:
        u = g[v].pop()
        # print("GO TO", u, g)
        stack.append(u)

if wrong:
    ans.pop(-1)

ans.reverse()

if len(ans) != n + 1:
    print("NO")
else:
    print("YES")
    print("".join(ans))

