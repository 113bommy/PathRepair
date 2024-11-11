n=int(input())
l=[int(i) for i in input().split()]
l=sorted(l)
s=0
for i in range(n):
    s+=((l[i]+l[n-1-i])*(l[i]+l[n-1-i]))
print(s/2)