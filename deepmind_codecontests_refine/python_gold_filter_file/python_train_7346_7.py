x=int(input())
import sys
n=0
l=[]
if x==1:
    print(1,'\n1')
    sys.exit()
for i in range(1,x+1):
    if x>=i:
        x=x-i
        n=n+1
        l.append(i)
    
print(n)
if x==0:
    for i in l:
        print(i,end=' ')
    sys.exit()
else:
    l.sort(reverse=True)
    for i in l:
        if x>0:
            l[l.index(i)]=i+1
            x=x-1
        else:
            break
for i in l:
        print(i,end=' ')
