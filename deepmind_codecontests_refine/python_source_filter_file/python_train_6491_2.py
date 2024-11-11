p,d=map(int,input().split())
req=[]
s=str(p)
n=len(s)
dec=0 
j=n-1
for i in range(0,n-1):
    a=s[j:]
    #print(a)
    j-=1 
    now=int(a)+1 
    req.append(now)

for i in range(len(req)):
    if req[i]<=d:
        dec=req[i]
def check(s):
    c=0 
    for j in range(len(s)-1,-1,-1):
        if s[j]=='9':
            c+=1 
        else :
            return c 
    return c 
#print(check(str(p)))
#print(check(str(p-dec)))
if check(str(p))==check(str(p-dec)):
    print(p)
else:
    print(p-dec)