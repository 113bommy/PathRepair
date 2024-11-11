import math
n = int(input())
count = 0
if n==1: print(3)
elif n==2: print(1)
elif n%2!=0: print(1)
else:
    for i in range(1,n+1):
        count = i
        m = (n*i) + 1
        for j in range(2,int(math.sqrt(m))+1):
            if m%j==0:
                print(count); exit()