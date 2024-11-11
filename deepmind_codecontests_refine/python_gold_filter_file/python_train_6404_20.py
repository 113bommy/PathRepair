n = input()
p = input()
result = ''
for i in range(len(n)):
    if n[i] == p[i]:
        result += '0'
    else:
        result += '1'
print(result)
