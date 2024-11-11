n = int(input())
l = list(map(int,input().split()))
cc = 0
c = l[0]
count=abs(l[0])
i = 1
while i<n:
    if l[i]<l[i-1]:
        k = i
        kk = 0
        while k<n:
            if l[k]>l[k-1]:
                count+=(c-l[k-1])
                c = l[k-1]
                i = k-1
                break
            else:
                if k == n-1:
                    count+=(c-l[k])
                    i = k
                    break
            k+=1
    elif l[i]>l[i-1]:
        k = i
        kk = 0
        while k<n:
            if l[k]<l[k-1]:
                count+=abs(l[k-1]-c)
                c = l[k-1]
                i = k-1
                break
            else:
                if k == n-1:
                    count+=(l[k]-c)
                    i = k
                    break
            k+=1
    i+=1
print(count)
        
        
    
        

    
    
    
