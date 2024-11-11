n= int(input())
l=[]
for _ in range(n):
    a= int(input())
    l.append(a)
l1= list(sorted(l))
l2= list(reversed(list(sorted(l))))
s=0
for i in range(n):
    s+= l1[i]*l2[i]
print(s%10007)
