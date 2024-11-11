a = input()
b = input()
i = 0
num = ''
while(i<len(a)):
    num += str(int(a[i]) ^ int(b[i]))
    i += 1
print(num)