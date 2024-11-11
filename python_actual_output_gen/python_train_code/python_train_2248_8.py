n,m=list(map(int,input().split()))
s=list(map(int,input().split()))
count=0
c=1
for x in s:
    if x>=c:
        steps=(x-c)
    else:
        steps=(x-c)+n
    count += steps
print(count)