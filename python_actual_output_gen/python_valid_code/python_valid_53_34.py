k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
count=0
for i in range(d):
    if(i%k!=0 and i%l!=0 and i%m!=0 and i%n!=0):
        count+=1
print(d-count)
