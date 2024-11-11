inp = input()
inp = inp[1:]
inp = inp[:-1]
if len(inp) > 1 :
    inp = inp.split(", ")
    print(len(set(inp)))
elif len(inp) == 0:
    print(0)

