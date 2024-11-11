n = int(input())
a = list(map(int,input().split()))
a.sort()
sum1 = 0
sum2 = 0
if n % 2 == 0:
    for i in range(n//2):
        sum1 += a[i]
    for i in range(n//2+1):
        sum2 += a[i]
else:
    for i in range(n//2):
        sum1 += a[i]
    for i in range(n//2,len(a)):
        sum2 += a[i]
print(sum1*sum1+sum2*sum2)
