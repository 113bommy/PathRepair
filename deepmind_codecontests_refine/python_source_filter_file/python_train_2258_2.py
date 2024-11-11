n=int(input())
l=list(map(int,input().split()))
d={}

def change(w,i,val):
    if d[w][0]==i:
        d[w][0]+=val
        return
    d[w][1]+=val
def isdone():
    for j,i in enumerate(l):
        if i in d:
            d[i].append(j)
        else:
            d[i]=[j]
isdone()
i=0
m=0
while True:
    if i>=n:
        break
    if l[i]!=l[i+1]:
        ind=max(d[l[i]])
        for j in range(ind,i+1,-1):
            l[j],l[j-1]=l[j-1],l[j]
            #change(l[j-1],j,-1)
            #change(l[j],j-1,1)
            d={}
            isdone()
            m+=1
        #print(l,d)
    i+=2
print(m)
