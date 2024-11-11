s = 0
a, b = map(int, input().split())
for i in range(0, 63):
    if 2**i-2**(i-2)-1 > b:
        break
    for j in range(0, i-1):
        if a<=2**i-2**j-1<=b:
            s+=1
print(s)