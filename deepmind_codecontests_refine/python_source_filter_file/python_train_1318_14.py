inp = input()


if not inp.count("-"):
    print("YES")
    exit(0)
if(inp.count("o") % inp.count("-") == 0):
    print("YES")
else:
    print("NO")
