n=int(input())
d=[]
e=[]
for i in range(n):
    p=[0,0]
    s=input()
    for j in s:
        if j==")":
            if p[0]!=0:
                p[0]-=1
            else:
                p[1]+=1
        else:
            p[0]+=1
    if p[1]-p[0]>=0:
        d.append(p)
    else:
        e.append(p)
d=sorted(d,key=lambda x:x[1])
e=sorted(e,key=lambda x:-x[0])
s=d+e
q=0
for i,j in s:
    if q<j:
        print("No")
        exit()
    else:
        q=q-j+i
if q==0:
    print("Yes")
else:
    print("No")