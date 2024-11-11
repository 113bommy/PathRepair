a=int(input())
e=0
for i in range(a):
    b,c,d=input().split()
    c=int(c)
    d=int(d)
    if c>2400 and c-d>0:
        e+=1
if e>0:
    print("YES")
else:
    print("NO")






