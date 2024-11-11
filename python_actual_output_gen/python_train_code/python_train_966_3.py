n = int(input())
s = list(input())
c = [0]*4
d =  0
for i in s:
    if i in ['1','2','3']:
        c[0]=1
        d += 1
    if i in ['1','4','7']:
        c[1]=1
    if i in ['3','6','9']:
        c[2]=1
    if i in ['7','0','9']:
        c[3]=1
if c==4 or ('0' in s and d) :
    print("YES")
    exit(0)
else:
    print("NO")
    exit(0)
        
        
