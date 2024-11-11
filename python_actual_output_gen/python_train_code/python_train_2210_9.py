a = input()
b = input()
result = ''
for i in range(len(a)):
    if a[i] == b[i]:
        result +='o'
    else:
        result += '1'
print(result)