a,b,c=map(int,input().split())
i=0
k=c
while (c - b*i)>=0:
    k=c-b*i
    if k%a==0:
        print('Yes')
        exit()
    i+=1
print('No')    
    
    