a = input()
if a.count('BAC') >= 1:
    print("Yes")
elif a.count('BCA') >= 1:
    print("Yes")
elif a.count('ABC') >= 1:
    print("Yes")
elif a.count('ACB') >= 1:
    print("Yes")
elif a.count('CAB') >= 1:
    print("Yes")
elif a.count('CBA') >= 1:
    print("Yes")
else:
    print("No")
