count=0
a = []
b = []
n = int(input(""))
for i in range(n):
    u,v = map(int, input("").split(" "))
    a.append(u)
    b.append(v)

for j in range(n-2):
    if((a[j] - b[j]) > a[j-1]):
        count += 1
    elif((a[j] + b[j]) < a[j+1]):
        count += 1
        a[j] = a[j] + b[j]

if(n>1):
    print(count+2)
else:
    print(1)