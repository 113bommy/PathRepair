h,w,K=map(int,input().split())
s=[]
for i in range(h):
    s.append(input())

ans=float("inf")
for i in range(2**(h-1)):
    cut=[]
    linecount=0
    for j in range(h-1):
        if (i>>j)%2==1:
            cut.append(j)
    counter=[0]*(len(cut)+1)
    for j in range(w):
        ncounter=[0]*(len(cut)+1)
        area=0
        flag=False
        for k in range(h):
            ncounter[area]+=int(s[k][j])
            if counter[area]+ncounter[area]>K:
                if ncounter[area]>k:
                    linecount=float("inf")
                flag=True
            if k in cut:
                area+=1
        if flag:
            counter=ncounter[:]
            linecount+=1
        else:
            for l in range(len(cut)+1):
                counter[l]+=ncounter[l]
    ans=min(ans,linecount+len(cut))
print(ans)
        



