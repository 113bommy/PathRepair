n,k,m=map(int,input().split())
a=list(map(int,input().split()))
flag=0
b=[0]*m
for x in a:
   #print (x%m)
   b[x%m]+=1
#print (b)
for i in range(m):
    #print (i)
    if b[i]>=k:
        print('Yes')
        flag=1
        cnt=k
        for x in a:
            if cnt==0:
                break
            if x%m==i:
                print(x,end=' ')
                cnt-=1
        exit(0)        
if flag==0:	
    print('No')