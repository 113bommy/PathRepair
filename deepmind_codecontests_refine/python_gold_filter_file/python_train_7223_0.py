import re

n = int(input())

for i in range(n):
    s = input()

    rainbow = re.search(r"\Amiao\.", s)
    freda = re.search(r"lala\.\Z", s)

    if rainbow and not freda:
        print("Rainbow's")
    elif freda and not rainbow:
        print("Freda's")
    else:
        print("OMG>.< I don't know!")
