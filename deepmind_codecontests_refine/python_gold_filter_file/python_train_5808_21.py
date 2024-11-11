N, A, B, C = map(int, input().split())
v = [A, B, C]
s = [-1 for i in range(N)]
for i in range(N):
    t = input()
    if t == "AB":
        s[i] = 0
    if t == "BC":
        s[i] = 1
    if t == "AC":
        s[i] = 2
ans = [-1 for i in range(N)]
OK = True

for i in range(N):
    p = s[i]
    q = (s[i]+1)%3
    if v[p] < v[q]:
        ans[i] = p
        v[p] += 1
        v[q] -= 1
    elif v[p] > v[q]:
        ans[i] = q
        v[p] -= 1
        v[q] += 1
    elif v[p] > 0:
        if i == N-1:
            ans[i] = p
            v[p] += 1
            v[q] -= 1
        elif s[i+1] == q:
            ans[i] = q
            v[p] -= 1
            v[q] += 1
        else:
            ans[i] = p
            v[p] += 1
            v[q] -= 1
    else:
        OK = False
        break

ch = ["A", "B" ,"C"]
if OK:
    print("Yes")
    for i in range(N):
        print(ch[ans[i]])
else:
    print("No")