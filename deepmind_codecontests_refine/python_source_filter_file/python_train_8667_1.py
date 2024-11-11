n=int(input())
a=list(map(int,input().split()))
b=[0]*100001
c=[0]*100001
for i in a:
    b[i]+=1
    c[b[i]]+=1
q=int(input())
for _ in range(q):
    e,z=input().split()
    z=int(z)
    if(e=='+'):
        b[z]+=1
        c[b[z]]+=1
    elif(e=='-'):
        c[b[z]]-=1
        b[z]-=1
    if(c[8]>0 or c[4]>1 or (c[6]>0 and c[2]>1) or (c[4]>0 and c[3]>2)):
        print('YES')
    else:
        print('NO')

        
        
    
        
