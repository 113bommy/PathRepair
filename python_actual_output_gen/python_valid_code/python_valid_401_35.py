s,n=[int(i)for i in input().split()]
p=False
d=sorted([[int(i)for i in input().split()]for j in range(n)])
m=max(d,key=lambda x:x[0])[0]
for x in d:
    if s > m:p=True;break
    if s >= x[0]:
        s+=x[1]
    else:
        break
print(["NO","YES"][p])