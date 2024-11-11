flags = input()
rev_flags = flags[::-1]
forward = False
backward = False
both = False
arr_1 = input()
arr_2 = input()
if arr_1 in flags:
    if arr_2 in flags[flags.index(arr_1) + len(arr_1):]:
        forward = True
if arr_1 in rev_flags:
    if arr_2 in rev_flags[rev_flags.index(arr_1) + len(arr_1):]:
        if forward:
            both = True
        else:
            backward = True
if both:
    print('both')
elif forward:
    print('forward')
elif backward:
    print('backward')
else:
    print('fantasy')