if __name__ == '__main__':
    r = int(input())

    mylist = []
    nylist = []

    for i in range(r):
        m, n = map(int, input().split())
        mylist.append(m)
        nylist.append(n)

    count = 0
    for i in range(r):

        if (mylist[i] < nylist[i]):
            count += 1
        else:
            pass

    print(count)
