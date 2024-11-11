k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
s=0
for i in range(0,d):
    if i%k==0:
        s+=1
    elif i%l==0:
        s+=1
    elif i%m==0:
        s+=1
    elif i%n==0:

        s+=1            
print(s)
