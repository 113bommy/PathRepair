while True:
    try:
        s = input()
        if s[4] != "s":
            if (s[0] == s[4] and s[0] == s[8]) or (s[2] == s[4] and s[2] == s[6]):
                print(s[4])
                continue
        for i in range(3):
            if s[i] != "s" and s[i] == s[i + 3] and s[i] == s[i + 6]:
                print(s[i])
                break
            elif s[i] != "s" and s[3*i] == s[3*i + 1] and s[3*i] == s[3*i + 2]:
                print(s[3*i])
                break
        else:
            print("d")
    except:
        break

