n=int(input())
a=[int(i) for i in input().split()]
z=min(a)
p=[]
for i in range(n):
    if a[i]==z:
        p.append(i)
h=[]
for i in range(len(p)-1):
    h.append(a[i+1]-a[i])
print(min(h)+1)
