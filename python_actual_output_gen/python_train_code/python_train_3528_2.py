def equivalent_strings(a, b):
    if(a == b):
        return True
    if(len(a) % 2 != 0):
        return False
    middle = len(a) // 2
    left_a = a[:middle]
    right_a = a[middle:]
    
    left_b = b[:middle]
    right_b = b[middle:]

    return (equivalent_strings(left_a, right_b) and equivalent_strings(right_a, left_b)) or (equivalent_strings(left_a, left_b) and equivalent_strings(right_a, left_b))

a = input()
b = input()

if(equivalent_strings(a, b)):
    print('YES')
else:
    print('NO')