def check(flags, first, second):
    if first not in flags or second not in flags:
        return False
    first_first_indx = flags.index(first)
    last_second_indx = flags.rindex(second)
    return first_first_indx + len(first) - 1 < last_second_indx


flags, first, second = input(), input(), input()
f = check(flags, first, second)
flags = flags[::-1]
b = check(flags, first, second)

if f and b:
    print('both')
elif f:
    print('forward')
elif b:
    print('backward')
else:
    print('fantasy')
