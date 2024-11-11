a = int(input())
b = 0
while True:
    if str(a + b).find('8') != -1:
        break
    b += 1
print(b)