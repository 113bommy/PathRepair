x = int(input())
a = 0
for i in range(1,x):
    for j in range(2,10):
        if i**j <= x:
            a = max(a,i**j)
print(a)