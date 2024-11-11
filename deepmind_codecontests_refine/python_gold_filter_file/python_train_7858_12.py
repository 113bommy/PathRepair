n=int(input())
a=list(map(lambda x: int(x),input().split()))
b=1
c=1
for i in range(1,len(a)):
    if(a[i]>=a[i-1]):
        b+=1
    else:
        b=1
    if(b>c):
        c=b
print(c)
