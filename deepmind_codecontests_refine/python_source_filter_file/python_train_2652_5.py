def main():
    m,t,r = map(int,input().split())
    times = list(map(int,input().split()))

    candles = 0
    burn = []

    prev = 0
    for time in times:
        diff = time-prev
        for j in range(len(burn)):
            burn[j] -= diff

        new = []
        for j in burn:
            if j > 0:
                new.append(j)

        burn = new[:]
        j = 1
        while len(burn) != r:
            if j < t:
                candles += 1
                burn.append(t-j+1)
                j += 1
            else:
                break

        if len(burn) != r:
            print(-1)
            return

        prev = time
        #print(burn)

    print(candles)

main()
