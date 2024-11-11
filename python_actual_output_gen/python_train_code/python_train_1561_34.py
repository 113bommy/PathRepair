a = input()
b = ''
for i in a:
    if i.lower() not in ['a','e','i','o','u']:
        b+='.'+i.lower()
print(b)
