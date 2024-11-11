k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
cntr=0
for i in range(d):
    if i%k==0 or i%l==0 or i%m==0 or i%n==0:
        cntr+=1
print(cntr)