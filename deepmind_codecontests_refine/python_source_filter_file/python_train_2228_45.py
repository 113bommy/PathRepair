n,m=map(int,input().split(' '))
l=sorted([int(x)for x in input().split(' ')])
a=l[-1]-l[0]
for i in range(m-n):
    a=min(a,l[i+n-1]-l[i])
print(a)