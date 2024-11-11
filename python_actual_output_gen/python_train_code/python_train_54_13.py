d,m=(int(i) for i in input().split())
ex=[int(i) for i in input().split()]
mx=0
for i in range(d-1):
    mx=max(mx,ex[i]-ex[i+1])
print(mx-m)
