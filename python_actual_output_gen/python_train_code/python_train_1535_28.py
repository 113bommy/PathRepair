a = input()
b = []
n = 0
table = list('qwertyuiopasdfghjklzxcvbnm')
for i in range(len(a)):
    if a[i] in table:
        b.append(a[i])
b = sorted(b)
for i in range(len(b)-1):
    if b[i+1] == b[i]:
        b[i+1] = None
for i in range(len(b)):
    if b[i] != None:
        n += 1
print(n)