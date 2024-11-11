a = int(input())
b = input()
x = 0
for i in range(1, int(a/2)):
    if (b[0:i] == b[i:i+i]):
        x = i
print(a - x)
