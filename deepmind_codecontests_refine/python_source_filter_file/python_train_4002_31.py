parol = input()
a1 = False
a2 = False
a3 = False
if len(parol)>=5:
    for i in range(len(parol)):
        if ord('A')<=ord(parol[i])<=ord('Z'):
            a1 = True
        elif ord('a')<=ord(parol[i])<=ord('z'):
            a2 = True
        elif ord('0')<=ord(parol[i])<=ord('9'):
            a3 = True
if a1 and a2 and a3:
    print('correct')
else:
    print('Too weak')
