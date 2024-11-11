s=input()
k=int(input())
j=0
for i in s:
    if(i!="?" and i!="*"):
        j+=1
a=[]
if(j==k):
    for i in s:
        if(i!="?" and i!="*"):
            a.append(i)
if(j>k):
    for i in s:
        if(i=="?" or i=="*"):
            if(j>k and len(a)>0):
                j-=1
                a.pop()
        if(i!="?" and i!="*"):
            a.append(i)
if(k>j):
    for i in s:
        if(i=="*"):
            if(k>j and len(a)>0):
                f=k-j
                for _ in range(f):
                    a.append(a[-1])
                j=k
        if(i!="?" and i!="*"):
            a.append(i)
if(len(a)!=k):
    print("Impossible")
else:
    print(*a,sep="")