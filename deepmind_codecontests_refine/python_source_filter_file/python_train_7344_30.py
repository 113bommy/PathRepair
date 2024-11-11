n,b,d=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
s=0
k=0
for i in range(n):
    if a[i]> b:
        break
    k+=a[i]
    if k>d:
        s+=1
        k=0
print(s)
    
