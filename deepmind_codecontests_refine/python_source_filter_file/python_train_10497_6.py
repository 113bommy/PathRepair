N,K = [ int(it) for it in input().split() ]
K2 = 2*K
li = [ (lambda x,y,z:[int(x)%K2,int(y)%K2,0 if z=="W" else 1] )(*(input().split())) for i in range(N)]

bm = [[0]*(K2+1) for i in range(K2+1)]
wm = [[0]*(K2+1) for i in range(K2+1)]
for x,y,z in li:
  if (z==0):
    wm[x+1][y+1] += 1
  else:
    bm[x+1][y+1] += 1

for i in range(1,2*K+1):
  for j in range(1,2*K+1):
    bm[i][j]=bm[i-1][j]+bm[i][j-1]-bm[i-1][j-1]+bm[i][j]
    wm[i][j]=wm[i-1][j]+wm[i][j-1]-wm[i-1][j-1]+wm[i][j]
sumb=bm
sumw=wm
ans=0
for i in range(K):
    for j in range(K):
        for _ in range(2):
            s=0
            s+=sumb[i][j]-sumb[i][0]-sumb[0][j]+sumb[0][0]#
            s+=sumb[i+K][j+K]-sumb[i][j+K]-sumb[i+K][j]+sumb[i][j]#
            s+=sumb[i][2*K]-sumb[0][2*K]-sumb[i][j+K]+sumb[0][j+K]#
            s+=sumb[2*K][j]-sumb[i+K][j]-sumb[2*K][0]+sumb[i+K][0]#
            s+=sumb[2*K][2*K]-sumb[i+K][2*K]-sumb[2*K][j+K]+sumb[i+K][j+K]#

            s+=sumw[i][j+K]-sumw[0][j+K]-sumw[i][j]+sumw[0][j]#
            s+=sumw[i+K][j]-sumw[i][j]-sumw[i+K][0]+sumw[i][0]#
            s+=sumw[2*K][j+K]-sumw[i+K][j+K]-sumw[2*K][j]+sumw[i+K][j]#
            s+=sumw[i+K][2*K]-sumw[i+K][j+K]-sumw[i][2*K]-sumw[i][j+K]#

            ans=max(ans,s)
            sumb,sumw=sumw,sumb

print(ans)
