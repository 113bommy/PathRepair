x=input().split()
n=int(x[0])
m=int(x[1])
z=int(x[2])
c=0
for i in range(1,z+1):
    if i%n==0 and i%m==0:
        c+=1
print(c)
