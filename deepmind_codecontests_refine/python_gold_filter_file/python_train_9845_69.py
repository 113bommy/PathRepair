




if __name__ == '__main__':

    t = int(input())

    ls = input()

    a = 0
    d = 0
    for i in ls:
        if i=="A":
            a += 1
        else:
            d += 1

    if a >d:
        print("Anton")
    elif a < d:
        print("Danik")
    else:
        print("Friendship")


