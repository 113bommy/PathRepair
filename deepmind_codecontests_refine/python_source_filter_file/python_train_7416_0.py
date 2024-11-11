array = []
h = 0
res = 0
cards = 0
maxi_cards = 10 ** 9 + 1
maxi_cards = 30
while cards <= maxi_cards:
    cards += 2 * (h + 1) + h
    h += 1
    array.append(cards)

len_array = len(array)


def search(array, n, begin, end):
    if begin == end:
        return begin
    middle = (begin + end) // 2
    # print(begin, end, middle)
    if array[middle] <= n:
        res = search(array, n, middle + 1, end)
    else:
        res = search(array, n, begin, middle)
    return res


T = int(input())
for t in range(T):
    n = int(input())
    res = 0
    # print(array)
    while True:
        # print("--")
        # print("n", n)
        # print(0, len_array)
        r = search(array, n, 0, len_array)
        # print("r", r)
        cards = array[r - 1]
        n -= cards
        if r == 0:
            break
        res += 1
    print(res)
