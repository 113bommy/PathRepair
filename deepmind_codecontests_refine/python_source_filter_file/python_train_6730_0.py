def main():
    n = int(input())
    measures = [int(x) for x in input().split()]
    m = min(measures)
    count = [measures.count(m + i) for i in range(3)]
    if count[2] == 0:
        print(n)
        print(' '.join([str(x) for x in measures]))
        return
    pairsOfOnesToSwap = min(count[0], count[2])
    pairsOfZerosToSwap = count[1]//2
    print(n - max(pairsOfZerosToSwap, pairsOfOnesToSwap))
    if pairsOfOnesToSwap >= pairsOfZerosToSwap:
        count = [x+y for x, y in zip(count, [-pairsOfOnesToSwap, 2*pairsOfOnesToSwap, -pairsOfOnesToSwap])]
    else:
        count = [x+y for x, y in zip(count, [pairsOfZerosToSwap, -2*pairsOfZerosToSwap, pairsOfZerosToSwap])]
    count = [max(0, x) for x in count]
    print(' '.join([str(x) for x in count[0] * [m] + count[1] * [m+1] + count[2] * [m+2]]))


if __name__ == "__main__":
    main()