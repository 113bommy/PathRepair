import sys

a, b, c, d, e, f = [float(x) for x in (sys.stdin.readline()).split()]

if(e == 0 and f != 0):
    print("Ron")
elif(f == 0):
    print("Hermione")
else:
    if(c == 0 and d != 0):
        print("Ron")
    elif(d == 0):
        print("Hermione")
    else:
        if(a == 0 and b != 0):
            print("Ron")
        elif(b == 0):
            print("Hermione")
        else:
            v = (b / a) * (d / c) * (f / e)
            if(v <= 1):
                print("Hermione")
            else:
                print("Ron")