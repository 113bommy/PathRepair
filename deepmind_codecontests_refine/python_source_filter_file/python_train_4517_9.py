n,k=map(int,input().split())

res = [n]

i=0
m=n-1

while i<k-1:
    res.append(m)
    m-=1
    i+=1

i=0
m=1

while i<(n-k):
    res.append(m)
    m+=1
    i+=1
    
print(' '.join(str(i) for i in res))