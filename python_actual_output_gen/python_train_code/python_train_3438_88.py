x = int(input())
a = 0
for i in range(1,x+1):
    for j in range(2,x):
        if i**j <= x:
            a = max(a,i**j)
print(a)