n=int(input())
ar=list(map(int,input().split()))
b=set()
maxx=0
for i in ar:
   while i in b:
     print(b.remove(i))
     i+=1
   b.add(i)
print(max(b)-len(b)+1)
print(b)

