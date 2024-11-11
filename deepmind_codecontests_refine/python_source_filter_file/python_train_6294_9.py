def valid(vars):
    my_list = [1, 2, 3]
    my_vals = vars.values()
    for i in my_list:
        if not(i in my_vals):
            return False
    return True

vars = {'A': 3, 'B': 3, 'C': 3}
for i in range(3):
    my_in = input()
    smaller = my_in[0] if my_in[1] == '<' else my_in[2]
    vars[smaller] -= 1
if not valid(vars):
    print("IMPOSSIBLE")
else:
    out = list("AAA")
    for key, val in vars.items():
        out[val - 1] = key
    print(''.join(out))
