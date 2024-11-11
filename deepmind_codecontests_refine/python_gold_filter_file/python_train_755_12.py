t = int(input())


def check_before(size, ls, i):
    if i-1 < 0:
        return False
    if ls[i - 1] != size:
        return True

    return False


def check_after(size, ls, i):
    if i+1 >= len(ls):
        return False
    if ls[i + 1] != size:
        return True

    return False


def check_bigger(sizes):
    biggest_i = 0
    biggest_s = 0

    first = sizes[0]
    flag = True
    repeated = []
    for i, size in enumerate(sizes):
        if size != first:
            flag = False

        if size >= biggest_s:
            biggest_s = size
            biggest_i = i
            repeated.append((biggest_s, biggest_i))

    if flag:
        return -1
    else:
        j = 0
        while j < len(repeated) and repeated[j][0] < biggest_s:
            j+=1
        repeated = repeated[j:]
        #print("repeated", repeated)
        for size, i in repeated:
            #print(size, i)
            #print(check_before(size, sizes, i), check_after(size, sizes, i))
            if check_before(size, sizes, i) or check_after(size, sizes, i):
                return i+1


for _ in range(t):
    n = int(input())
    sizes = list(map(int, input().split()))
    resp = check_bigger(sizes)
    print(resp)
