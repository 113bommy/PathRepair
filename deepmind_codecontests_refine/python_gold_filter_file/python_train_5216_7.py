n=int(input())
b=list(map(int,input().split()))
j=0
p=1
q=1

while(j<n-1):
    if b[j+1]/b[j]>2:
        q=1
    else:
        q+=1
    p=max(p,q)
    j+=1
print(p)
