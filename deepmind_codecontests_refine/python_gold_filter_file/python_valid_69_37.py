tw=1
l=[]
lnll=0
while tw<10**17:
    tmp=tw
    l1=[]
    while tmp>0:
        l1.insert(0,tmp%10)
        tmp=tmp//10

    l.append(l1)
    tw=2*tw
    lnll+=1
    
lnl=[]
for a in l:
    lnl.append(len(a))

t=int(input())
for _ in range(t):
    n=int(input())
    l1=[]
    ln1=0
    while n>0:
        l1.insert(0,n%10)
        n=n//10
        ln1+=1

    digit=[[],[],[],[],[],[],[],[],[],[]]
    idx=[0]*lnll
    for i in range(lnll):
        digit[l[i][idx[i]]].append(i)

    for d in l1:
        tmp=digit[d]
        digit[d]=[]
        for j in tmp:
            idx[j]+=1
            if idx[j]<lnl[j]:
                digit[l[j][idx[j]]].append(j)
    
    M=100
    for i in range(lnll):
        M=min(M,lnl[i]+ln1-2*idx[i])
    print(M)
