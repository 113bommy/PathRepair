from collections import defaultdict
n,k=[int(el) for el in input().split()]
h=[int(el) for el in input().split()]

l=len(h)
d=defaultdict(int)
maxh=h[0]
minh=h[0]
for i in range(l):
    d[h[i]]+=1
    maxh=max(maxh,h[i])
    minh=min(minh,h[i])



if n==1 or minh==maxh:
    print(0)
    raise SystemExit

s=list(d.keys())

cur1=s.pop()
curval=0
out=1
while s!=[]:
    cur2=s.pop()
    qnt=d[cur1]
    dif=cur1-cur2
    val=dif*qnt
    if curval+val<k:
        curval += val
        d[cur2]+=d[cur1]
        dele = d.pop(cur1)
        cur1=cur2
        continue
    if curval+val==k:
        if s==[]:
            print(out)
            raise SystemExit
        else:
            out+=1
            curval=0
            d[cur2]+=d[cur1]
            cur1=cur2
            continue

    q=(k-curval)//qnt
    if q==0:
        out+=1
        curval=0
        s.append(cur2)
    else:
        curval=0
        d[cur1-q]=d[cur1-q]+d[cur1]
        dele=d.pop(cur1)
        cur1=cur1-q
        out+=1
        s.append(cur2)

print (out)

