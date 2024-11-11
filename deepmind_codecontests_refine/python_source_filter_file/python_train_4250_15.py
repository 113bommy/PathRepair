a,b,k=map(int,input().split())
i=0
c=0
while(c!=k):
    i+=1
    if a%i==0 and b%i==0:
        c+=1
print(i)
