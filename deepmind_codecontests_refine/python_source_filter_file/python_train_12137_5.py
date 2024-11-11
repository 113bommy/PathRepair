import sys
import operator

n = int(input())
t = list(map(int,sys.stdin.readline().split()))

m = []
for i in range(n-1):
    m.append([i+1,t[i+1]])

m = sorted(m, key=operator.itemgetter(1), reverse=True)
m = [[0, t[0]]] + m 

f = 0
c = 1
ans = []
while c < n and m[f][0]!=0:
    ans.append(str(m[f][0]+1)+" "+ str(m[c][0]+1))
    c+=1
    m[f][1] = m[f][1] -1
    if m[f][1] ==0:
        f+=1

if c!=n:
    print(-1)
else:
    print(len(ans))
    print("\n".join(ans))
