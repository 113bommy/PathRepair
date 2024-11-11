n = int(input())

acc = 1
for i in range(n):
    acc = acc*(i+1)

acc = acc/(n*n/2)

print(int(acc))