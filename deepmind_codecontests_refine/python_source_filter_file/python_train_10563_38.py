#499B
n,m = map(int,input().split())
d ={}
for _ in range(m):
    a,b = map(str,input().split())
    a1,b1 = len(a),len(b)
    if a1<=b1:
        d[a] = a
    else:
        d[a] = b
print(d)
l = list(map(str,input().split(" ")))
for i in l:
    print(d[i],end=" ")

        

    