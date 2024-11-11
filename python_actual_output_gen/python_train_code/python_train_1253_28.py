s = input()
if s[0] == "A" and "C" in s[2:-1] and s[1:].replace("C","").islower():
    print("AC")
else:
    print("WA")