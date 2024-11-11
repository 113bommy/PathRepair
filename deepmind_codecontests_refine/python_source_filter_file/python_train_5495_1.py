k,n=map(int,input().split())
a=list(map(int,input().split()))
j=[int(k-a[-1])]
for i in range(n-1):
    j.append(a[i+1]-a[i])
print(k-max(j))