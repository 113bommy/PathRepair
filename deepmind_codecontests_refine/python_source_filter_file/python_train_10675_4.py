x = input()
n = len(x)
t = x
i, j = 0, n - 1
while t[i] == '0':
    i += 1
b = -1
for k in range(i, n):
    if t[k] == '.':
        b = 1
if b == 1:
    while t[j] == '0':
        j -= 1
temp = t[i : j + 1]
n = len(temp)
index = n
for i in range(n):
    if temp[i] == '.':
        index = i
        break
exp = ""
if index == 1:
    exp = temp.strip('.').strip('0')
elif index == 0:
    i = index + 1
    while ord(temp[i]) <= ord('0'):
        i += 1
    t = temp[i + 1:].replace('.', '').strip('0')
    x = '.' + t
    if t == "":
        x = ''
    exp = temp[i] + x + 'E' + str(index - i)
else:
    t = temp[1:].replace('.', '').strip('0')
    x = '.' + t
    if t == "":
        x = ''
    exp = temp[0] + x + 'E' + str(index - 1)
print(exp)