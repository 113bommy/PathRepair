n=int(input())
max=0
count=0
x,y=input().split()
for i in range(n-1):
    x1,y1=input().split()
    if x==x1 and y==y1:
        count+=1
    if count>max:
        max=count
    else:
        count=0
    x=x1
    y=y1
print(max+1)
