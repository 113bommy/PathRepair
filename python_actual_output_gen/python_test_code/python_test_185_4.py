N = int(input())
S = input()

d = []
o = c = 0
for i in range(N):
    if S[i] == '(':
        o += 1
    else:
        c += 1
    d.append(o - c)
x = min(d)
print('(' * -x + S + ')' * (d[-1] - x))
