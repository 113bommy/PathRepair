
n=int(input())
l=list(map(int,input().split()))
four=0
two=0
cnt={}
for x in l:
    if x not in cnt:
        cnt[x]=1
    else:
        cnt[x]+=1
for k,v in cnt.items():
    four+=(v//4)
    two+=((v%4)//2)
q=int(input())
d=cnt.copy()
for i in range(q):
    s,p=input().split()
    p=int(p)
    if(s=='+'):
        if p  not in d:
            
            cnt[p]=d[p]=1
        else:
            cnt[p]=d[p]
            d[p]+=1
    else:
        cnt[p]=d[p]
        d[p]-=1
        #print(d[p]," ",cnt[p])
    four+=(d[p]//4-cnt[p]//4)
    two+=((d[p]%4)//2-(cnt[p]%4)//2)
    #print(four,two)
    if(four>=2 or (four==1 and two>=2)):
        print("YES")
    else:
        print("NO")