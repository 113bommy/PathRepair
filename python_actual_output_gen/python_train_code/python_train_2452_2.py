n = int(input())
a = [int(x) for x in input().split()]
dp = [0]*n
neg = 0
x = 0
for i in range(n):
    if(a[i]< 0):
        x = x +  abs(a[i]+1)
        neg+=1
    elif(a[i] > 0):
        x = x + a[i]-1
    elif(a[i]==0):
        x = x + abs(abs(i)-1)
if(neg%2==1):
    if(0 not in a):
        x = x + 2
print(x)

