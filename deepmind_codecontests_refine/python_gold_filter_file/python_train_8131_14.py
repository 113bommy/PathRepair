
def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    k = int(buflist[1])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))

    a = list(sorted(a))
    pos = 0
    neg = 0
    for i in range(k):
        if pos < len(a):
            print(a[pos] - neg)
            neg = a[pos]
        else:
            print(0)
        while pos < len(a):
            if a[pos] - neg <= 0:
                pos += 1
            else:
                break

if __name__ == '__main__':
    main()
