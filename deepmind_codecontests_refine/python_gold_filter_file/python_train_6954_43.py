h,w=map(int,input().split())
l=list()
l.append('#'*(w+2))
for i in range(h):
    l.append("#"+input()+"#")
l.append('#'*(w+2))
si=[[0 for i in j] for j in l]
sj=[[0 for i in j] for j in l]
for i in range(h+2):
    k=0
    for j in range(w+2):
        if l[i][j]==".":
            k+=1
        else:
            for f in range(j-k,j):
                si[i][f]=k
            k=0
for j in range(w+2):
    k=0
    for i in range(h+2):
        if l[i][j]==".":
            k+=1
        else:
            for f in range(i-k,i):
                sj[f][j]=k
            k=0
ans=0
for i in range(h+2):
    for j in range(w+2):
        ans=max(ans,sj[i][j]+si[i][j])
print(ans-1)