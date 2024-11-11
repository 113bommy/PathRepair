n = int(input())
s = [input() for i in range(n)]

cnt = 0

def is_symmetry(s_):
    for k in range(n):
        for l in range(n):
            if s_[k][l] != s_[l][k]:
                return False
    return True

for i in range(n):
    i_ = (n+i)%n
    s_ = s[i_:] + s[:i_]
    if is_symmetry(s_):
        cnt += 1

print(cnt*n)