n=int(input())
a=[int(i) for i in input().split()]
ma=max(a)
s=0
j=0
for i in range(n):
    if a[i]!=ma:
        j+=1
        s+=a[i]
print(ma*i-s)