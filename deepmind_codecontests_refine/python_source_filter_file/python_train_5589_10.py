s = input()
a = int(s[s.index('.')-1])
b = int(s[s.index('.')+1])

if a == 9:
    print("GOTO Vasilisa")
elif a < 9 and b < 5:
    print(s[:s.index('.')])
else:
    print(int(s[:s.index('.')])+1)        