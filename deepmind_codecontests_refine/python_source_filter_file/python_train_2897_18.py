n = int(input())
s = [input() for i in range(n)]

cnt = 0

def is_symmetry():
    for k in range(n):
        for l in range(k+1, n):
            if s_[k][l] != s_[l][k]:
                return false
    return true

for i in range(n):
    i_ = (n+i)%n
    s_ = s[i_:] + s[:i_]
    if is_symmetry():
        cnt += 1

print(cnt*n)