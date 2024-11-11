n = input()
u = False
l = False
k = False
for i in n:
    if i.isupper():
        u = True
    elif i.islower():
        l = True
    elif i.isdigit:
        k = True
if u and k and l and len(n) >= 5:
    print('Correct')
else:
    print('Too weak')