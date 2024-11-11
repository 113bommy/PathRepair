a = input()
b = input()

h, v = ord(a[0]) - ord(b[0]), ord(a[1]) - ord(b[1])
print(max(v, -v, h, -h))

while(v != 0 and h != 0):
    r = ""
    if(h > 0):
        r = "L"
        h -= 1
    if(h < 0):
        r = "R"
        h += 1
    if(v < 0):
        r += "U"
        v += 1
    if(v > 0):
        r += "D"
        v -= 1

    print(r)
