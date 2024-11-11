s = input()
print("AC" if s[0] == "A" and s[2:len(s)-1].count("C") == 1 and s.replace("C","",1).islower() else "WA")