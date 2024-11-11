a,b = map(int,input().split())
c,d = map(int,input().split())
res = -1
for i in range (100):
    for j in range(100):
        if (b+(a*i)) == (d+(c*j)):
            res = (b+a*i)
            break
    else:
        continue
    break
print(res)