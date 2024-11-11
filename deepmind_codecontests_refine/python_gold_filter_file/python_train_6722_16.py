import string


def reversed_list(l, start, end):
    if start >= end:
        return l
    l[start], l[end] = l[end], l[start]
    return reversed_list(l, start + 1, end - 1)



def main_function():
    n = int(input())
    possiblities = [n, 1]
    for b in range(1, n + 1):
        if not n % b:
            a = n // b
            if b >= a:
                if b - a < possiblities[0] - possiblities[1]:
                    possiblities = [b, a]
    return f"{possiblities[1]} {possiblities[0]}"


print(main_function())