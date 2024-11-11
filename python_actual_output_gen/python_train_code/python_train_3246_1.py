n=int(input())
hor=[False]*n
ver=[False]*n
for i in range(n*n):
    k=list(map(int,input().split()))
    if (hor[k[0]-1]==True and ver[k[1]-1]==True):
        break
    if not(hor[k[0]-1]==True or ver[k[1]-1]==True):
        ver[k[1]-1]=True
        hor[k[0]-1]=True
        print(i+1,end=' ')    
    
