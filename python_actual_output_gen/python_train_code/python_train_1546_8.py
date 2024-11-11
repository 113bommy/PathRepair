if __name__ == "__main__":
    d = input()

    b = d
    for i, a in enumerate(d):
        if a == "0":
            b = d[i:]
        elif a == "1":
            break

    c = sum(1 for a in b if a == '0')
    if c >= 6:
        print("yes")
    else:
        print("no")
