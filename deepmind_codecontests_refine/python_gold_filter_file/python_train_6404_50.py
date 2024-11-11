a = input()
b = input()

result = ''

for i in range(len(a)):
    if a[i] == b[i]:
        result += '0'
    else:
        result += '1'
print(result)