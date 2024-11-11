n=int(input())
l=list(map(int,input().split()))
l.sort()
c=0
p=[]
for i in l:
    l.count(i)
    p.append(l)
print(max(p))