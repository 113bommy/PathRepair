n,m,z=map(int,input().split())
s=0
for i in range(1,z+1):
    if i%n==0 and i%m==0:
        s+=1
print(s)
