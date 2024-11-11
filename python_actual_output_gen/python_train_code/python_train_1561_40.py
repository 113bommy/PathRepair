word = input()
w = ''
for i in word:
    str.lower(i)
    if i not in ['a','e','i','o','u','y']:
        w = w + '.' + i
print(w)