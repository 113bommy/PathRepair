def possibility(a, b):
    if a > b:
        temp = a
        a = b
        b = a
    #b>a
    c = 1
    for i in range(b+1, a+b+1):
        c *= i
    for i in range(1, a):
        a *= i
    return c/a

if __name__ == "__main__":
    s1 = input()
    s2 = input()

    one = [0, 0]
    two = [0, 0]
    question = 0

    for i in range(0, len(s1)):
        if s1[i] == "+":
            one[0] += 1
        elif s1[i] == "-":
            one[1] += 1
        if s2[i] == "+":
            two[0] += 1
        elif s2[i] == "-":
            two[1] += 1
        else:
            question += 1
    one[0] -= two[0]
    one[1] -= two[1]
    #print(one)
    if one[0] < 0 or one[1] < 0:
        print(0)
        #impossible
    elif one[0] == 0 or one[1] == 0:
        print(1/pow(2, one[0]+one[1]))
    else:
        print(possibility(one[0], one[1]) / pow(2, one[0]+one[1]))