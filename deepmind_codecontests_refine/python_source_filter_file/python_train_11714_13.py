def reversed_list(l, start, end):
    if start >= end:
        return l
    l[start], l[end] = l[end], l[start]
    return reversed_list(l, start + 1, end - 1)



def main_function():
    d, L, v_1, v_2 = [int(i) for i in input().split(" ")]
    t = (L - d) / (v_1 + v_2)
    print('{0:.20f}'.format(t))

print(main_function())