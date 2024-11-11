def calcchips(n,m):
    if n==1:
        return m-n
    if m==1 and n>=1:
        return 0
        
    j=1
    l=[0]*(n)
    count=0
    while j+count<=m:
        for i in range(n):
            if j+count<=m:
                l[i]= l[i] + j
                count= count+j
                j+=1
            else:
                return abs(m- sum(l))
            
        j=1
    return abs(m- sum(l))

n,m= input().split()
n= int(n)
m= int(m)

print(calcchips(n,m))
