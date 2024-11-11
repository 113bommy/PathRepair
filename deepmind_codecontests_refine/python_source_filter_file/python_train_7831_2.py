'''
26th april 2020 sunday
'''


def all_equal(a):
    for i in range(1, len(a)):
        if a[i] != a[i - 1]:
            return False
    return True


for _ in range(int(input())):
    a = input()
    a = list(a)

    if all_equal(a):
        print(''.join(a))
    else:
        i = 1
        while i < len(a):
            print('10', end='')
            i += 1
        print('')
