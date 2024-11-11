s = input()

lower = 0
upper = 0

if s.lower() == "house":
    print(s.lower())
elif s.lower() == "vip":
    print(s.upper())
else:
    for i in range(len(s)):
        if (s[i].islower()):
            lower = lower + 1
        else:
            upper = upper + 1
    
    if lower == upper:
        print(s.lower())
    else:
        print(s)