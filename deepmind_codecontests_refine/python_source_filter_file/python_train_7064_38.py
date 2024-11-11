s = input()
if 0 < s.find("C") < (s.find("F") or s.find("F", 2)):
    print("Yes")
else:
    print("No")