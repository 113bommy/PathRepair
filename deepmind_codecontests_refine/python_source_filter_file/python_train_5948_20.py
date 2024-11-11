x = int(input())
y = input()
z=[]
l = y[0]
count = 1
for c in range(1,x):
    if c + count>=x:
        break
    z.append(c)
    p = z[c-1]+count
    print(p)
    l = l + y[p-1]
    count = count+c


print(z)
print(l)