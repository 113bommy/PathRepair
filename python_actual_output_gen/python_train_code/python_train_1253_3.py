s=input()
print("AC" if s[0]=="A" and "C" in s[2:-1] and s[1:0].replace("C","c",1).islower() else "WA")