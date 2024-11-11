def rs(): return input().rstrip()
def ri(): return int(rs())
def ra(): return list(map(int, rs().split()))

def is_odd(a):
    return (a % 2) == 1

def is_even(a):
    return (a % 2) == 0

t = ri()
for _ in range(t):
    n = ri()
    arr = ra()

    if len(arr) == 1:
        if is_odd(arr[0]):
            print(-1)
        else:
            print("1\n1")
    elif len(arr) > 1:
        f = arr[0]
        s = arr[1]

        if is_even(f):
            print("1\n1")
        elif is_even(s):
            print("1\n2")
        else:
            print(1)
            print(1, 2)
