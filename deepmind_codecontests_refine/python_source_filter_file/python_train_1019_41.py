N = int(input())
S = str(input())

a = S.count('.')
r = a

for i in range(N):
    if S[0] == '#':
        a += 1
    else:
        r -= 1
    a = min(r, a)

print(a)
