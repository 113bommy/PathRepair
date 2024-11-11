s = input()
a = s.find("C")
b = s.rfind("F")

if -1 < a < b:
    print("Yes")
else:
    print("No")