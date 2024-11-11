s = input()
if s.find("C") != -1 and s.find("F") != -1 :
    print("Yes" if s.find("C") < s.rfind("F") else "No")
else :
    print("No")
