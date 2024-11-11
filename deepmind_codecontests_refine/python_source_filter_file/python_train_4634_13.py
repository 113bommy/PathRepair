sl = input()
word = list('hello')

k = 0

for i in sl:
    if k >= 4:
        break
    elif i == word[k]:
        k += 1
        continue
    else:
        continue
print('YES' if k >= 5 else 'NO')
