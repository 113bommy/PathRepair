n=int(input())
l2=[]
for i in range(n):
    c=0
    l1=[[0,0,1],[0,1,0],[1,0,0],[0,1,1],[1,0,1],[1,1,0],[1,1,1]]
    l=list(map(int,input().split()))
    l.sort()
    for j in l1:
        if(l[0]-j[0]>=0 and l[1]-j[1]>=0 and l[2]-j[2]>=0):
            l[0]=l[0]-j[0]
            l[1]=l[1]-j[0]
            l[2]=l[2]-j[2]
            c=c+1
    l2.append(c)
for i in l2:
    print(i)
