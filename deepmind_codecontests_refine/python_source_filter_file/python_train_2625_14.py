t=int(input())
for x0 in range(t):
    n,p,k = input().split()
    n=int(n)
    p=int(p)
    k=int(k)
    array = list(map(int,input().split()))
    array.sort()
    cumm=[]
    i=0
    while(i<len(array)):
        if(i==0 or i==1):
            cumm.append(array[i])
        else:
            cumm.append(array[i]+cumm[i-k])
        i+=1
    
    i=0
    maxm=0
    while(i<len(array)):
        if(cumm[i]<=p):
            maxm=max(maxm,i+1)
        else:
            if(i%2==0 and cumm[i]-cumm[i%k]<=p):
                maxm=max(maxm,i)
        i+=1
    print(maxm)