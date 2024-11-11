n = input()
p = float(n)
l = n.split('.')
a = l[0]
b = int(l[1][0])
if int(a[-1]) != 9 and b < 5:
    print(int(a))
elif int(a[-1]) != 9 and b >= 5:
    print(int(a)+1)
elif int(a[-1]) == 9:
    print("GOTO Vasilisa.")
