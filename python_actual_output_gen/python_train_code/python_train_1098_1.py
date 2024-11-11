n=int(input())
l=[]
for i in range(n):
    s=input()
    l.append(s)
a=l.count(l[0])
b=n-a
for i in range(n):
    if i!=l[0]:
        x=i
        break
if a>b:
    print(l[0])
else:
    print(l[i])