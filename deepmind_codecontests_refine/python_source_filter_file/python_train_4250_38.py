a,b,k=map(int,input().split())
z=[]
for i in range(1,a):
    if a%i==0 and b%i==0:
        z.append(i)
print(z[k-1])