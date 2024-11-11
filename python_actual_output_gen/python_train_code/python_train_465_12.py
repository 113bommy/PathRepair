a = int(input())
b = input()
x = 0
for i in range(1, int(a/2)+1):
    if b[:i] == b[i:i+i]:
        x = i
print(a - x)
