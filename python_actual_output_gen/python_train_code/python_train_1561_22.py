string = input()
result = ''
for char in string:
    if char in 'aoyeui':
        continue
    else:
        result += '.' + char.lower()
print(result)