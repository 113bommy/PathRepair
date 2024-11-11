s = input()
a = s.find("C")
b = s.rfind("F")

if a < b:
    print("Yes")
else:
    print("No")