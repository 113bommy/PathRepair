n = int(input())
a = 1
for i in range(1,n):
    for j in range(2,n):
        if i**j <= n:
            a = max(a,i**j)
print(a)