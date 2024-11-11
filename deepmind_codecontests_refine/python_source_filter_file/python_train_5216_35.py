#n,m = map(int, input().strip().split(' '))
n=int(input())
lst = list(map(int, input().strip().split(' ')))
l=[1]*(n)
if n==1:
    print(1)
else:
    j=0
    i=1
    c=0
    m=0
    while(i<n and j<n):
        if lst[i]<=lst[j]*2:
            c+=1
        else:
            if c>m:
                m=c
            c=0
            
        i+=1
        j+=1
        
    print(max(m+1,1,c))