import math
n=int(input())
prime=[True]*(n+2)
for i in range(2, int(math.sqrt(n+1))+1):
    if (prime[i]):
        for j in range(2*i, n+2, i):
            if (j<len(prime)):
                prime[j]=False
if (n==1 or n==2):
    print(1)
else:
    print(2)
for i in range(2, n+2):
    if (prime[i]):
        print(1, end=' ')
    else:
        print(2, end=' ')
