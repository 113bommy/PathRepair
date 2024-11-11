N = int(input())
S = str(input())

a = S.count('.')
r = a

for i in range(N):
    if S[0] == '#':
        a += 1
    else:
        a -= 1
    r = min(r, a)

print(r)