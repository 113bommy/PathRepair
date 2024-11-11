import sys

#sys.stdin = open("seq.in")

N = int(input())
S = input()
d = [0] * N
k = -1
m = 0
for i in range(N):
    if S[i] == '[':
        k += 1
        d[i] = k
    else:
        d[i] = k
        k -= 1
    m = max(m, k)
H = 2 * m + 3
W = N
for k in range(N - 1):
    if S[k] == '[' and S[k + 1] == ']':
        W += 3

field = [["."] * W for i in range(H)]
j = 0
def pr(file):
 for line in field:
    for c in line:
        print(c, end='')
    print()

for k in range(N):
    h = H - 2 * d[k]
    pad = ((H - h) // 2)
    for i in range(H):
        if i < pad or i > H - pad - 1:
            field[i][j] = ' '
        elif i == pad or i == H - pad - 1:
            field[i][j] = '+'
        else:
            field[i][j] = '|'
    j += 1
    if k < N - 1 and S[k] == '[' and S[k + 1] == ']':
        for _ in range(3):
            for i in range(H):
                field[i][j] = ' '
            j += 1
#pr(file=sys.stderr)
for i in range(H):
    for j in range(W):
        if field[i][j] != '+':
            continue
        if j < N - 1 and field[i][j+1] == ' ':
            field[i][j + 1] = '-'

        if j > 0 and field[i][j-1] == ' ':
            field[i][j - 1] = '-'
#print()
pr(sys.stdout)