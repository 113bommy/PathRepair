def bs(l,low,high,x):
    index=-1
    while(low<=high):
        mid=(low+high)//2
        if l[mid]==x:
            return mid
        elif l[mid]<x:
            index=mid
            low=mid+1
        else:
            high=mid-1
    return index
n=100000
l=[0]*(n+1)
for i in range(1,100000):
    l[i]=i*i
for t in range(int(input())):
    k=int(input())
    index=bs(l,0,n-1,k)
    #print(index)
    m=k-(index*index)

    if m==0:
        print(index,1,sep=" ")
    elif m<=(index+1):
        row=m
        col=index+1
        print(row,col,sep=" ")
    else:
        row=index+1
        col=index+1-(m-(index+1))
        print(row,col,sep=" ")