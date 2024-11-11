n,k=map(int,input().split())
a=list(map(int,input().split()))
d=[]
s=set()
for i in a:
    if i not in s:
        d.append(i)
        s.add(i)
    if len(d)>k:
        s.remove(d.pop())
        
print(len(d))
print(*d[::-1])
