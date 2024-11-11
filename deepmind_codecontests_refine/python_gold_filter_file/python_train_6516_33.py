n = int(input())
if n == 1:
    print('a')
elif n == 2:
    print("aa")
elif n == 3:
    print("bba")
else:
    req = n // 4
    if req * 4 == n:
        print("aabb"*req)
    else:
        rem = n - req * 4
        print("aabb" * req, end="")
        if rem == 1:
            print("a")
        elif rem == 2:
            print("aa")
        elif rem == 3:
            print("aab")
