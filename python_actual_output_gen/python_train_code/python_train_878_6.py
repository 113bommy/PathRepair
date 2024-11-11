b = int(input())
result = 0
for i in range(1, b):
    if i**2>b:
        break
    if b%i==0:
        result += 1
    if i**2 == b:
        result -= 1
print(result)
