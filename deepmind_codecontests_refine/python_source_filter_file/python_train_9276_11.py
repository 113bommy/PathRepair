n=int(input())
a=[]
for i in range(n):
    a.append({int(x) for x in input().split()})
s=a[0]
for i in a:
    s=s.intersection(i)
for i in s:
    print(i, end=" ")
    