n=list(map(int,input().split()))
l=[]
s=[0]*116
w=[0]*116
f=0
t=0
p=0
q=0
for i in range(n[0]):
    o=list(input())
    l+=[o]
for i in range(n[0]):
    for j in range(n[1]):
        if(l[i][j]=="B"):
            p=i
            q=j
            break
    if((p or q)!=0):
        break
for i in range(n[0]):
    if("B" in l[i]):
        t+=1
p=p+t//2+1
q=q+t//2+1
print(p,q)