k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

a = [0]*(d+1)
for i in range(1,d+1,k):
    if(i%l==0 or i%k==0 or i%m==0 or i%n==0):
        a[i]=1
print(sum(a))