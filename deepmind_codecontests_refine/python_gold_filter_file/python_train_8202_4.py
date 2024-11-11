import math
n=int(input())
n_root=math.ceil(n**(0.5))

sum=0
for i in range(1, n_root+1):
    if n%i==0 and (i+1)<int(n/i):
        sum=sum+int(n/i)-1
print(int(sum))
