def Nineteen(string):
    n = string.count("n")
    i = string.count("i")
    e = string.count("e")
    t = string.count("t")
    temp = 0
    while not (n - 1 < 2 or i < 1 or e < 3 or t < 1):
        temp += 1
        n -= 2
        i -= 1
        e -= 3
        t -= 1
    return temp


print(Nineteen(input()))