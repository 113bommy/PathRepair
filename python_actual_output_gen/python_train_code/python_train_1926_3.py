n=int(input())
l=[]
for _ in range(n):
   a,b=map(int,input().split())
   l.append((b,a))
l.sort( reverse = True )

#print(l)
c=1
p=0
i=1
for b,a in l:
    c += b
    p += a
    if not c:
        break
print (p)