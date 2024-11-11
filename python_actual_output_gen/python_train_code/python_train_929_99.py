n,h=(int(x) for x in input().split())
p=[int(x) for x in input().split()]
w=0
for i in range(n):
    if p[i]>=h:
        w+=2
    else:
        w+=1
print(w)