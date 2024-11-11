a = input()
n = 0
i = 0
e = 0
t = 0
for j in a:
    if j == 'n':
        n += 1
    if j == 'i':
        i += 1
    if j == 'e':
        e += 1
    if j == 't':
        t += 1
if n > 3:
    n = n//2 + 1
else:
    n = n//3
min = n
e = e//3
if e < min:
    min = e
if i < min:
    min = i
if t < min:
    min = t
print(min)
