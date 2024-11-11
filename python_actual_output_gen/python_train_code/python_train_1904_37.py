M = int(input())
D = [];C = []
S = 0
ans = -1
for i in range(M):
  d,c = map(int,input().split())
  D.append(d);C.append(c)
  S += d*c
  ans += c
kaisu = S//10
#print(ans,kaisu)
ans += kaisu
print(ans)
