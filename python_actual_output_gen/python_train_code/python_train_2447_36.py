s = input()
if "C" in s:
    if "F" in s[s.index("C"):]:
        print("Yes")
        exit()
    print("No")