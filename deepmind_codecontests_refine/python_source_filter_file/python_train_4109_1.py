a = int(input())
b = int(input())
c = int(input())
if a != 1 and b != 1 and c != 1:
    print(a * b * c)
else:
    if a == 1 and b == 1 and c == 1:
        print(3)
    else:
        if b == 1:
            if a > c:
                print(a * (c + 1))
            else:
                print(c * (a + 1))
        else:
            if a == 1:
                b += 1
                if c == 1:
                    b += 1
                else:
                    b *= c
            else:
                if c == 1:
                    b += 1
                    b *= a
        print(b)
