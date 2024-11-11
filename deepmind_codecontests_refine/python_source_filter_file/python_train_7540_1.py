n = int(input())
lis = list(map(int,input().split()))
ma=r=0
mi=a=0
for i in range(n):
    if i%2==0:
        a+=lis[i]
    else:
        a-=lis[i]
    ma=max(ma,a)
    mi=min(mi,a)
    r+=lis[i]
mat=[[' ']*(r) for i in range(ma+abs(mi)+2)]    
ro=ma
col=0
for i in range(n):
    if i%2==0:
        ro-=1
        for k in range(lis[i]):
            mat[ro][col]='/'
            ro-=1
            col+=1
    else:
        ro+=1
        for k in range(lis[i]):
            mat[ro][col]='\\'
            ro+=1
            col+=1
for i in mat[:]:
    print(*i)            
            


