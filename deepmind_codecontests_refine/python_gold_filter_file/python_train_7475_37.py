N,Q = map(int,input().split())
s = input()

cnt = 0
n = [0]
for i in range(N-1):
    if s[i]+s[i+1] == 'AC':
        cnt += 1
    n.append(cnt)


for i in range(Q):
    l,r = map(int,input().split())
    print(n[r-1]-n[l-1])