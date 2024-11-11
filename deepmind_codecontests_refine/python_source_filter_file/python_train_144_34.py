n,c=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
p=[]
for i in range(n-1):
    z=a[i]
    o=a[i+1]
    h=z-o
    p.append(h-c)
print(max(p))
