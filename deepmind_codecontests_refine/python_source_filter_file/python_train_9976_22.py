x = int(input())
ma = 0
for i in range(1,100):
    for j in range(1,100):
        if i**j <= x:
            ma = max(ma,i**j)
print(ma)