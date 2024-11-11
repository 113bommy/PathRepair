def main(a):
    if a == 1:
        return -1
    return "{} {}".format(a-1, a-1)

print(main(int(input())))
