n = int(input())
if n == 2:
    print(-1)
elif n == 3:
    print("aab")
    print("c.b")
    print("cdd")
elif n == 4:
    print("aabc")
    print("ddbc")
    print("efgg")
    print("efhh")
elif n == 5:
    print("abbcc")
    print("a..da")
    print("b..da")
    print("bqq.b")
    print("ccaab")
else:
    if n % 2 == 0:
        r = n // 2
        for i in range(r - 1):
            if i == 0:
                print("a" + "." * (r - 2) + "zz" + "." * (r - 3) + "aa")
            else:
                if i % 2 == 1:
                    print(
                        "." * (i - 1) + "ab" + "." * (n - i * 2 - 3) + "bb" + "." * (i)
                    )
                else:
                    print(
                        "." * (i - 1) + "ba" + "." * (n - i * 2 - 3) + "aa" + "." * (i)
                    )
        if r % 2 == 0:
            print("z" + "." * (r - 3) + "a" + "." * (n - r) + "z")
            print("z" + "." * (n - r) + "a" + "." * (r - 3) + "z")
        else:
            print("z" + "." * (r - 3) + "b" + "." * (n - r) + "z")
            print("z" + "." * (n - r) + "b" + "." * (r - 3) + "z")
        for i in range(r - 2, -1, -1):
            if i == 0:
                print("aa" + "." * (r - 3) + "zz" + "." * (r - 2) + "a")
            else:
                if i % 2 == 1:
                    print(
                        "." * (i) + "bb" + "." * (n - i * 2 - 3) + "ba" + "." * (i - 1)
                    )
                else:
                    print(
                        "." * (i) + "aa" + "." * (n - i * 2 - 3) + "ab" + "." * (i - 1)
                    )
    else:
        r = n // 2
        for i in range(r - 1):
            if i == 0:
                print("a" + "." * (r - 2) + "zz" + "." * (r - 2) + "aa")
            else:
                if i % 2 == 1:
                    print(
                        "." * (i - 1) + "ab" + "." * (n - i * 2 - 3) + "bb" + "." * (i)
                    )
                else:
                    print(
                        "." * (i - 1) + "ba" + "." * (n - i * 2 - 3) + "aa" + "." * (i)
                    )
        if r // 2 == 0:
            print("." * (r - 2) + "a..p" + "." * (r - 2) + "z")
            print("z" + "." * (r - 2) + "..p" + "." * (r - 2) + "z")
            print("z" + "." * (r - 2) + "qq.a" + "." * (r - 2))
        else:
            print("." * (r - 2) + "b..p" + "." * (r - 2) + "z")
            print("z" + "." * (r - 2) + "..p" + "." * (r - 2) + "z")
            print("z" + "." * (r - 2) + "qq.b" + "." * (r - 2))

        for i in range(r - 2, -1, -1):
            if i == 0:
                print("aa" + "." * (r - 2) + "zz" + "." * (r - 2) + "a")
            else:
                if i % 2 == 1:
                    print(
                        "." * (i) + "bb" + "." * (n - i * 2 - 3) + "ba" + "." * (i - 1)
                    )
                else:
                    print(
                        "." * (i) + "aa" + "." * (n - i * 2 - 3) + "ab" + "." * (i - 1)
                    )
