def binsearch(lofpoints,l,r,w,arr):
    if(l>r):
        return "None"
    mid=(l+r)//2
    if(lofpoints[mid][0]==w and arr[mid]==1):
        if(mid==0):
            arr[mid]=0
            return mid
        elif(lofpoints[mid-1][0]!=w or arr[mid-1]==0):
            arr[mid]=0
            return mid
        else:
            return binsearch(lofpoints,l,mid-1,w,arr)
    if(lofpoints[mid][0]==w and arr[mid]==0):
        return binsearch(lofpoints,mid+1,r,w,arr)
    if(lofpoints[mid][0]<w):
        return binsearch(lofpoints,mid+1,r,w,arr)
    if(lofpoints[mid][0]>w):
        return binsearch(lofpoints,l,mid-1,w,arr)


n=int(input())
lofpoints=[]
for i in range(n):
    l=input().split()
    x=int(l[0])
    y=int(l[1])
    lofpoints.append((y-x,x,y))
lofpoints.sort()
w=input().split()
wi=[int(i) for i in w]
arr=[1 for i in range(n)]
lsol=[]
done=1
#print(lofpoints)
for i in range(n):
    x=binsearch(lofpoints,0,n-1,wi[i],arr)
    #print(x)
    if(x=="None"):
        done=0
        break
    elif(lsol==[]):
        lsol.append((lofpoints[x][1],lofpoints[x][2]))

    elif(lofpoints[x][1]<lsol[-1][0] and lofpoints[x][2]<lsol[-1][1]):
        done=0
        break
    else:
        lsol.append((lofpoints[x][1],lofpoints[x][2]))
#print(lsol)
if(done==1):
    hashi=dict()
    for i in range(n):
        hashi[(lsol[i][0],lsol[i][1])]=i
    for i in hashi:
        x=i[0]
        y=i[1]
        t=hashi[i]
        if((x,y+1) in hashi):
            if(hashi[(x,y+1)]<t):
                done=0
                break
        if((x+1,y) in hashi):
            if(hashi[(x+1,y)]<t):
                done=0
                break

    if(done==0):
        print("NO")
    else:
        print("YES")
    for i in lsol:
        print(i[0],i[1])
else:
    print("NO")
