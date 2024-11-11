n,d=list(map(int,input().split()))
m=k=0
for i in range(d):
    s=input()
    if '0' in s:
        k+=1
    else:
        if k>m:
            m=k
            k=0
if k>m:
    m=k
print (m)
