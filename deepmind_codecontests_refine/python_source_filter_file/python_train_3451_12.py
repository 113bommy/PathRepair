import math

n=int(input())
x=1
lis=[]
while True:
    if x%2==1:
        k=int(math.log2(n))+1
        n^=(2**k-1)
        lis.append(k)
    else:
        n+=1
    if math.log2(n+1)==int(math.log2(n+1)):
        break
    x+=1
print(x)
for i in lis:
    print(i,end="")