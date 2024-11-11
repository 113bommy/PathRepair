k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
t=0
for i in range(1,d+1):
    if k==1 or l==1 or m==1 or n==1:
        k=d
        break
    elif (i%k==0 or i%l==0 or i%m==0 or i%n==0):
        t+=1
    
print(t)


