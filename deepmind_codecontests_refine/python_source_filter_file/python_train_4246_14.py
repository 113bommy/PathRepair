n,m = map(int,input().split())
t = [0]*n
q = []
r = 0
for i in range(n):
    q.append([])
for i in range(m):
    a,b = map(int,input().split())
    q[a-1].append(b-1)
    q[b-1].append(a-1)
num = 0
for i in range(n):
    if(t[i] == 0):
        num += 1
        cnt = 0
        stc = [i]
        while(len(stc) > cnt):
            x = stc[cnt]
            for j in range(len(q[x])):
                if(t[q[x][j]] == 0):
                    t[q[x][j]] = num
                    stc.append(q[x][j])
            cnt += 1
        r = max(cnt-1,r)
print(r)