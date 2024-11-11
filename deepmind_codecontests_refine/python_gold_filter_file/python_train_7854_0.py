l=[]
for i in range(int(input())):
    l+=[list(map(int,input().split()))]
l.sort(key=lambda x:(x[0],x[1]))
d=0
for i in l:
    if i[1]>=d:
        d=i[1]
    else:
        d=i[0]
print(d)