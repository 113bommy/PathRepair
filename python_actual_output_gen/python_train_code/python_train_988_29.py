n,k=map(int,input().split())
r=input().split()
c=0
m=0
for i in range(1,len(r)):
    if r[i]!=r[i-1]:
        m+=1
        if m>=c:
            c=m+1
    else:
        m=0
print(c)
