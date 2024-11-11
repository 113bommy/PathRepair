S = input()
T = input()

q = int(input())

s = [0]*len(S)
t = [0]*len(T)
for i, x in enumerate(S):
    if x == "A":
        s[i] += 1
for i, x in enumerate(T):
    if x == "A":
        t[i] += 1

ss = [0]*(len(S)+1)
for i, x in enumerate(s):
    ss[i+1] = s[i] + ss[i]
tt = [0]*(len(T) + 1)
for i, x in enumerate(t):
    tt[i+1] = t[i]+tt[i]


for i in range(q):
    a, b, c, d = map(int, input().split())

    k = (ss[b] - ss[a-1])
    l = (tt[d] - tt[c-1])
    k += ((b - a + 1) - k)*2
    l += ((d - c + 1) - l)*2
    if abs(k-l) % 3 == 0:
        print("YES")
    else:
        print("NO")
