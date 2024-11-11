n=int(input())
l=[]
for i in range(n):
    a,b = map(int,input().split())
    l.append([a,b])
l.sort(key=lambda x: x[1])
c=t=0
for i in range(len(l)):
    if t<int(l[i][0]):
        t=int(l[i][1])
        c+=1
print(c)

