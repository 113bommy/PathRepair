n=int(input())
l=list(map(int,input().split()))

for i in range(2,n):
    l[i]=l[i]+l[i-2]
#print(l)
s=l[-1]
for i in range(1,n):
    if i%2==0:
        s=max(s,l[-1]-l[i-2]+l[i-1])
    else:
        if i>1:
            s=max(s,l[-2]-l[i-2]+l[i-1])
        else:
            s=max(s,l[-2]+l[i-1])
print(s)