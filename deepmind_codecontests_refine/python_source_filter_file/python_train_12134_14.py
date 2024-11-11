n=int(input())
a=list(map(int,input().split()))

s=1
m=1
p=a[0]
for i in a[1:]:
    if i>p:
        s=s+1
        if s>m:
            m=s
    else:
        s=1
    p=i
    
print(s)