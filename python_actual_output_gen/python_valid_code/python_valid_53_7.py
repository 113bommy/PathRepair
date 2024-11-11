k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
c=0
for i in range(1,d+1):
    if i%k==0 or i%l==0 or i%m or i%n:
        c+=1
print(c)
