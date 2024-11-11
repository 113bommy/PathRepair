def tree(d,parent):
    if len(d[parent])==0:
        return
    for i in d[parent]:
        d[i].remove(parent)
    for i in d[parent]:
        parent=i
        tree(d,parent)

def check_happy(d,h,p):
    for i in range(1,n+1):
        if (p[i-1]-h[i-1])%2!=0 or (abs(h[i-1]))>p[i-1]:
            return 1
        if len(d[i])==0:
            continue
        val=0
        pval=0
        for j in d[i]:
            val+=h[j-1]
            pval+=p[j-1]
        if val+pval>h[i-1]+p[i-1]:
            return 1
    return 0
        
def fix(d,p,node):
    if len(d[node])==0:
        return p[node-1]
    val=p[node-1]
    for i in d[node]:
        val+=fix(d,p,i)
    p[node-1]=val
    return val

t= int(input())
for _ in range(t):
    try:
        n,m=map(int,input().split())
        p=list(map(int,input().split()))
        h=list(map(int,input().split()))
        d={}
        for i in range(1,n+1):
            d[i]=[]
        for i in range(n-1):
            a,b=(map(int,input().split()))
            d[a].append(b)
            d[b].append(a)
        #print(d)
        #exit()
        tree(d,1)
        #print(d)
        fix(d,p,1)
        x=check_happy(d,h,p)
        if(x):
            print('NO')
            continue 
        print('YES')
    except:
        print('NO')