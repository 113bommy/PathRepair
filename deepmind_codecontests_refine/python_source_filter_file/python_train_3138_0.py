n=int(input())
a=[int(x) for x in input().split()]
a.sort()
min1=a[0]
p=0
i=0
for i in a:
    for j in range(1,int(i**0.5+1)):
        if i%j==0 and (min1+i-min1*j-i//j)>0:
            p=min1+i-min1*j-i//j
print(sum(a)-p)