n=int(input())
k=0
for i in range(n-1):
    a,b=map(int,input().split())
    if a<b:
        print('Happy Alex')
        k=k+1
        break
if k==0:
    print('Poor Alex')
    

    
