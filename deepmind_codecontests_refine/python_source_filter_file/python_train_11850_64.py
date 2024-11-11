import math
N,M=map(int,input().split())
max=1
for i in range(1,int(math.sqrt(M))+1):
    if M%i==0 and i>=N:
        max=M/i
        break
    if M%i==0 and M/i>=N:
        max=i
print(max)