a,b,c=[int(i) for i in input().split()]
k=0
for i in range(a,b+1):
    if c%i==0:
         k=k+1
print(k)