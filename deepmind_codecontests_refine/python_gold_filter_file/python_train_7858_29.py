t=int(input())
p=0
lst=list(map(int,input().split()))
max1=0
for i in range(t-1):
    if(lst[i]<=lst[i+1]):
        p+=1
    else:
        p=0
    if(p>max1):
        max1=p
print(max1+1)