n=int(input())
l=[]
for i in range(0,n):
    l.append(sum(map(int,input().split())))
y=l[0]
x=sorted(l,reverse=True)
print(l.index(y)+1)