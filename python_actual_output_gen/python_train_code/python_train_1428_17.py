n = int(input())
k = n%9
if (k%2):
    k=(k+9)//2
else:
    k = k//2
l = []
for i in range(10):
    q = k + 9*i
    a = n-q
    if(a>0):
        b = str(a)
        c = 0
        for i in b:
            c+= int(i)
        if (c+a == n): l.append(a)
sorted(l)
print(len(l))
for i in range(len(l)):
    print(l[i])
