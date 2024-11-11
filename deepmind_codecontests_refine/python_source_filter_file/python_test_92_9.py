for _ in range(int(input())):
    line = input()
    k = line.count("ab") - line.count("ba")

    if k == 0:
        print(line)
    elif k == 1:
        print(line[:-2], "a", sep="")
    else:
        print(line[:-2], "b", sep="")
