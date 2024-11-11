a = int(input())
b = input()
x = 0
for i in range(1, int((a+1)/2)):
    if b[:i] == b[i:i+i]:
        x = i - 1
print(a - x)
