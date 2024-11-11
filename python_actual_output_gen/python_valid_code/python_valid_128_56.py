a = input()
b = ['H', 'Q', '9', '+']
n = 0
for i in a:
    if i in b:
        n += 1
if n > 0:
    print("YES")
else:
    print('NO')