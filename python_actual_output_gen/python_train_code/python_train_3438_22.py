x = int(input())
a = 1
for i in range(1,x+1):
    for j in range(2,4):
        if i**j <= x:
            a = max(a,i**j)
print(a)