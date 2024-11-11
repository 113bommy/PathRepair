n = int(input())
s=['' for _ in range(n)]
for i in range(n):
    s[i]=input()
#x=[[0,0] for _ in range(n)]
hp,hm=0,0
p=[]
m=[]
for i in range(n):
    t=s[i]
    lv=0
    mn=0
    for u in t:
        if u == '(':
            lv+=1
        elif u == ')':
            lv-=1
        mn=min(mn,lv)
    #x[i][0],x[i][1]=lv,mn
    if lv>=0:
        p.append([lv,mn])
        hp+=lv
    else:
        lv*=-1
        m.append([lv,mn+lv])
        hm+=lv
if hp!=hm:
    print('No')
    exit()
p.sort(key=lambda x: x[1],reverse=1)
m.sort(key=lambda x: x[1],reverse=1)
h=0
lv,mn=0,0
for a,b in p:
    lv+=a
    mn+=b
    if mn<0:
        print('No')
        exit()
    mn=lv
lv,mn=0,0
for a,b in m:
    lv+=a
    mn+=b
    if mn<0:
        print('No')
        exit()
    mn=lv
print('Yes')

#print(lv,mn)
    
