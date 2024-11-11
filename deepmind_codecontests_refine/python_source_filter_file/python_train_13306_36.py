import sys


L=int(input())-1
if L==1:
    print(2,1)
    print(1,2,0)
    print(1,2,1)
    sys.exit()

M=0
threelist=[]
j=1
i=1
while i<=10**6:
    i=3**j-1
    threelist.append(i)
    j+=1


threelist=threelist[::-1]

j=0
while True:
    if L>=threelist[j]:
       break
    else:
        j+=1

node=len(threelist)-j

PATH=[]
for i in range(2,2+node):
    PATH.append((i,i+1,0))

    PATH.append((i,i+1,3**(node+2-i-1)))
    PATH.append((i,i+1,2*3**(node+2-i-1)))
    M+=3

while L>0:
    j=0
    while True:
        if L>=threelist[j]:
            break
        else:
            j+=1

    k=len(threelist)-j
    rest=L-(3**k-1)

    PATH.append((1,node+2-k,rest))
    M+=1

    L=rest-1

    if L==0:
        PATH.append((1,node+2,0))
        M+=1
        break
    if L==1:
        PATH.append((1,node+2,0))
        PATH.append((1,node+2,1))
        M+=2
        break

print(node+2,M)
for pa in PATH:
    print(pa[0],pa[1],pa[2])
