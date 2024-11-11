a, b = map(int, input().rstrip().split(" "))
z = list(input())

if a==1 and b==1:
    print(0)
elif b == 0:
    print(z)
else:
    if int(z[0]) > 1:
        z[0] = "1"
        b -= 1
    print(z[0], end="")
    i = 1
    while i < a :
        if int(z[i]) != 0 and b:
            z[i] = "0"
            b -= 1

        print(z[i], end="")
        i += 1