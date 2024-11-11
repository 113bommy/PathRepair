d={}
try:
    while True:
        n=int(input())
        if n in d:
            d[n]+=1
        else:
            d[n]=1
except EOFError:
    pass
a=[]
m=max(d.value())
for key, value in d:
    if value == m:
        a.append(key)
a.sort()
for i in a:
    print(i)