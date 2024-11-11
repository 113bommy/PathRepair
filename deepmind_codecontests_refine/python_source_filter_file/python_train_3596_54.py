n,x = map(int,input().split())
a = []
b = []
count = 0
for i in range(n):
    s = list(map(str,input().split()))
    a.append(s)
    if a[i][0]== "+":
        b.append(int(a[i][1]))
    else:
        b.append(-int(a[i][1]))

for i in range(len(b)):
    if x+b[i]>0:
        x = x+b[i]
    else:
        x = x
        count = count+1
print(x,count)
        