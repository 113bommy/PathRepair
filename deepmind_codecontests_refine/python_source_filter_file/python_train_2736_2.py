import sys
import math
t=int(input())
def fn(l,i,j,l2):
    if(l==[1,1,1,1]):
        l1=[[i,j,i+1,j,i,j+1],[i,j+1,i+1,j+1,i+1,j],[i,j,i,j+1,i+1,j+1],[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 4
    elif(l==[1,0,0,0]):
        l1=[[i,j,i,j+1,i+1,j],[i,j,i,j+1,i+1,j+1],[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 3
    elif(l==[0,1,0,0]):
        l1=[[i,j,i,j+1,i+1,j+1],[i,j,i,j+1,i+1,j],[i+1,j,i,j+1,i+1,j+1]]
        l2+=l1
        return 3
    elif(l==[0,0,1,0]):
        l1=[[i,j,i+1,j+1,i+1,j],[i,j,i,j+1,i+1,j],[i+1,j,i,j+1,i+1,j+1]]
        l2+=l1
        return 3
    elif(l==[0,0,0,1]):
        l1=[[i+1,j,i,j+1,i+1,j+1],[i,j,i,j+1,i+1,j+1],[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 3
    elif(l==[1,1,0,0]):
        l1=[[i,j,i+1,j,i+1,j+1],[i+1,j,i+1,j+1,i,j+1]]
        l2+=l1
        return 2
    elif(l==[1,0,1,0]):
        l1=[[i,j,i,j+1,i+1,j+1],[i+1,j,i,j+1,i+1,j+1]]
        l2+=l1
        return 2
    elif(l==[1,0,0,1]):
        l1=[[i,j,i+1,j,i,j+1],[i+1,j,i,j+1,i+1,j]]
        l2+=l1
        return 2
    elif(l==[0,1,1,0]):
        l1=[[i,j,i,j+1,i+1,j+1],[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 2
    elif(l==[0,1,0,1]):
        l1=[[i,j,i+1,j,i,j+1],[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 2
    elif(l==[0,0,1,1]):
        l1=[[i,j,i+1,j,i,j+1],[i,j,i,j+1,i+1,j+1]]
        l2+=l1
        return 2
    elif(l==[0,1,1,1]):
        l1=[[i,j+1,i+1,j,i+1,j+1]]
        l2+=l1
        return 1
    elif(l==[1,0,1,1]):
        l1=[[i,j,i+1,j,i+1,j+1]]
        l2+=l1
        return 1
    elif(l==[1,1,0,1]):
        l1=[[i,j,i,j+1,i+1,j+1]]
        l2+=l1
        return 1
    elif(l==[1,1,1,0]):
        l1=[[i,j,i+1,j,i,j+1]]
        l2+=l1
        return 1
    else:
        return 0
for w in range(t):
    n,m=(int(i) for i in input().split())
    l=[]
    l2=[]
    s=0
    for i in range(n):
        l.append(list(input()))
    if(n%2==0):
        if(m%2==0):
            for i in range(0,n,2):
                for j in range(0,m,2):
                    l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                    s+=fn(l1,i+1,j+1,l2)
                    l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
        else:
            for i in range(0,n,2):
                for j in range(0,m-1,2):
                    l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                    s+=fn(l1,i+1,j+1,l2)
                    l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
                j+=1
                l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                s+=fn(l1,i+1,j+1,l2)
                l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
    else:
        if(m%2==0):
            for i in range(0,n-1,2):
                for j in range(0,m,2):
                    l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                    s+=fn(l1,i+1,j+1,l2)
                    l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
            i+=1
            for j in range(0,m,2):
                l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                s+=fn(l1,i+1,j+1,l2)
                l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
        else:
            for i in range(0,n-1,2):
                for j in range(0,m-1,2):
                    l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                    s+=fn(l1,i+1,j+1,l2)
                    l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
                j+=1
                l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                s+=fn(l1,i+1,j+1,l2)
                l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
            i+=1
            for j in range(0,m-1,2):
                l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
                s+=fn(l1,i+1,j+1,l2)
                l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
            j+=1
            l1=[int(l[i][j]),int(l[i][j+1]),int(l[i+1][j]),int(l[i+1][j+1])]
            s+=fn(l1,i+1,j+1,l2)
            l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]='0','0','0','0'
    print(s)
    for i in range(s):
        print(*l2[i])