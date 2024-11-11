h,w,m=map(int,input().split())
table=[]
H=[0]*h
W=[0]*w
li_h=[]
li_w=[]

for i in range(m):
    h1,w1=list(map(int,input().split()))
    table.append((h1-1,w1-1))
    H[h1-1]+=1
    W[w1-1]+=1

h_flag=0
w_flag=0

Hm=max(H)
Wm=max(W)

Hh=[i for i, x in enumerate(H) if x == HM]
Ww=[i for i, x in enumerate(W) if x == Wm]

cnt=0

for (h, w) in table:
    if H[h] == HM and W[w] ==  Wm:
        cnt += 1

if cnt<len(Hh)*len(Ww):
    print(HM+Wm)
else:
    print(HM+Wm-1)

