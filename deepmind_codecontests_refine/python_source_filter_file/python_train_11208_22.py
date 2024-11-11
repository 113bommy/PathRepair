def remove(n, name):
    count = 0
    while "xxx" in name:
        name = name.replace("xxx","xx")
        count += 1
    print(count)


def fileName(n, name):
    if "xxx" not in name:
        print(0)
    elif "xxx" in name:
        remove(n, name)

n = input()
name = input()
fileName(n, name)