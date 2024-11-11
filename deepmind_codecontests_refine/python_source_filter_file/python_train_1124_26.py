import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,Q = map(int,readline().split())
S = 'x' + readline().rstrip().decode('utf-8') + 'x'
query = read().decode('utf-8').split()

# ここに居れば左右に落ちない、ぎりぎり
L = 1; R = N
for T,D in zip(query[-2::-1],query[-1::-1]):
    if D == 'L':
        if S[L] == T:
            L += 1
        if S[R+1] == T:
            R += 1
    else:
        if S[R] == T:
            R -= 1
        if S[L-1] == T:
            L -= 1
    if L > R:
        break

x = R-L+1
if x <= 0:
    x = 0
print(x)