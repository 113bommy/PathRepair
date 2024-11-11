import math

n = int(input())
a = [int(x) for x in input().split()]
#print(a)
maxNum = -10000000001
for i in range(1, math.ceil(math.sqrt(n))):
    if n % i == 0:
        t = n // i
        if t > 2:
            for j in range(i):
                k = 0
                num = 0
                #b = []
                while k < n:
                    num += a[k+j]
                    #b.append(a[k+j])
                    k += i
                #print(i, b)
                #print(num)
                maxNum = max(maxNum, num)
        if i > 2:
            for j in range(t):
                k = 0
                num = 0
                #b = []
                while k < n:
                    num += a[k+j]
                    #b.append(a[k+j])
                    k += t
                maxNum = max(maxNum, num)
                #print(t, b)
                #print(num)
print(maxNum)
