a,b,c=map(int,input().split())
s=0
for i in range(a,b):
    if c%i==0:s+=1
print(s)

