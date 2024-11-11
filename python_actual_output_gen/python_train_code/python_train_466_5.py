s = input()

o = s.count("o")
d = s.count("-")

if o == 0 or d == 0 or o%d == 0:
    print("YES")
else:
    print("NO")