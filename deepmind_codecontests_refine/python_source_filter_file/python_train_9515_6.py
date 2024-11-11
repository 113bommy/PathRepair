n = int(input())
a = [int(x) for x in input().split()]
jml=0
for i in range(n):
    jml+=a[i]
p=0
s=0
for i in a:
    if i == 0:
        s+=1
        if s>p:
            p=s
    elif s == 0:
        s-=1
    if p==0:
        p-=1

print(p+jml)
