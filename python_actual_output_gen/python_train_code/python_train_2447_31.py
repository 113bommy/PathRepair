s = input()

if s.find("C") < (s.find("F") or s.find("F", 2)):
    print("Yes")
else:
    print("No")