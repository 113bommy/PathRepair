from itertools import permutations
l=list(permutations(range(0, 5))) 
p=[]
m=[]
for _ in range(5):
    m=list(map(int,input().split()))
    p.append(m)
res=0
for i in range(len(l)-1): 
    a=l[i][0]
    b=l[i][1]
    c=l[i][2]
    d=l[i][3]
    e=l[i][4]
    r = p[a][b]+p[b][a]+2*(p[c][d]+p[d][c])+p[b][c]+p[c][b]+2*(p[d][e]+p[e][d])
    res=max(r,res)
print(res)
    