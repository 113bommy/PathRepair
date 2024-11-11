D = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for _ in range(D)]
t = [int(input()) for _ in range(D)]

v = 0
last = [0 for _ in range(26)]

for i in range(D):
    last[t[i]-1] = i+1
    v += s[i][t[i]-1]
    for j in range(26):
        v -= c[j]*(d-last[j])
    print(v)
