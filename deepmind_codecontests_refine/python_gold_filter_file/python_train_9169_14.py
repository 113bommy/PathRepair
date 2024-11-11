n=int(input())
l=list(map(int,input().split()))
l.sort()
x=0
p=[]
for i in l:
    x=l.count(i)
    p.append(x)
print(max(p))