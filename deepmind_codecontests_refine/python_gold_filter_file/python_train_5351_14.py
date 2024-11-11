r,c=[int(i) for i in input().split()]
s=0
l=[]
num=0
nu=0
for i in range(r):
    a=input()
    if 'S' not in a:
        s+=c
        num+=1
    l.append(a)


for i in range(c):
    k=0
    for j in range(r):
        
        if l[j][i]=='S':
            break
        else:
            k+=1
    
    if k==r:
        s+=r
        nu+=1
print(s-num*nu)
        

