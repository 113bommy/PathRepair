inp_str = "45"

new_str = ""
if (len(inp_str)>=2):
    new_str += inp_str[-2] + inp_str[-1]
    if int(new_str) % 4 ==0:
        print(4)
    else:
        print(0)
else:
    if int(inp_str) % 4 == 0:
        print(4)
    else:
        print(0)

