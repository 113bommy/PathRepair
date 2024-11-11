n,b,d=map(int,input().split())
l=list(map(int,input().split()))
l1=[]
for i in range(len(l)):
    if(l[i]<=b):
        l1.append(l[i])
    else:
        continue
s,c=0,0
for i in range(len(l1)):
    s+=l[i]
    if(s<=d):
        c+=0
    else:
        c+=1
        s=0
print(c)

