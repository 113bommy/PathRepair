n = input()

def sum_of_digits(n):
    if len(list(n)) == 1:
        return -1
    list_ = list(map(int,list(n)))
    m = sum(list_)
    if m > 9:
        print(m)
        return 1 + sum_of_digits(str(m))
    else:
        return 0

print(sum_of_digits(n)+1)
