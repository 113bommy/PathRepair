def masking(n):
    s = ""
    for i in str(n):
        if i == "4" or i == "7":
            s += i
    if not s:
        return 0
    return int(s)

a, b = map(int, input().split())

if b >= a:
    print(b)
elif len(str(b)) == len(str(a)):
    print(int("1"+str(b)))
else:
    while True:
        a+=1
        if masking(a) == b:
            print(a)
            break
















