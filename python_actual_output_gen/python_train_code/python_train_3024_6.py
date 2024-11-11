n,m = map(int,input().split())
l = []
for i in range(m):
    a,b = map(int,input().split())
    l.append((a,b))
d = sorted(l,key = lambda x: x[1] ,reverse = True)
count = 0
print(d)
for i in d:
    if n>0:
        if n-i[0] >=0:
            count +=(i[0])*i[1]
            n -=i[0]
        else:
            count += (n)*i[1]
            n = 0
print(count)
