a,b,c = map(str,input().split())
a = int(a)
if c == "week":
    if a == 2 or a == 1:
        print(53)
    else:
        print(52)
elif c == "month":
    if a == 30:
        print(11)
    elif a == 31:
        print(7)
    else:
        print(12)