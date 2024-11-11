a=[int(q) for q in input().strip().split()]
b={}
for k in range(a[0]):
    d=input().split()
    b[d[1]]=d[0]
for k in range(a[1]):
    d=input().split()
    for p in b:
        if p in d[1]:
            print(d[0]+' '+d[1]+' #'+b[p])
            break