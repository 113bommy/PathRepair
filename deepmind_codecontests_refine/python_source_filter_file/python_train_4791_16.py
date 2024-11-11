def main():

    """ ????????? """
    H = int(input().strip())
    hkeys = list(map(int,(input().split())))
    for i in range(H):
        txts = []
        id = i + 1
        txts.append("node {}:key = {},".format(id, hkeys[i]))
        parent = int(id / 2)
        if parent != 0:
            txts.append("parent key = {},".format(hkeys[parent-1]))
        left = id * 2
        if left > 0 and left <= H:
            txts.append("left key = {},".format(hkeys[left-1]))
        right = left + 1
        if right > 0 and right <= H:
            txts.append("right key = {},".format(hkeys[right-1]))
        print("{} ".format(" ".join(txts)))

if __name__ == '__main__':
    main()