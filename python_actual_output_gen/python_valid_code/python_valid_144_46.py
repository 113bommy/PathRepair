n,c=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
a.insert(0,0)
k=-1
for i in range(1,len(a)):
    if a[i]-a[i-1]>c:
        k=i
print(n-k+1)
