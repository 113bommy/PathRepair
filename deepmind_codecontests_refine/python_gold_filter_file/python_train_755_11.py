for _ in range(int(input())):
    input()
    aqua = list(map(int, input().split()))

    max_aqua = max(aqua)
    if min(aqua) == max_aqua:
        print(-1)
    else:
        # точно есть доминирующая
        min_index = aqua.index(min(aqua))

        max_r = max(aqua[min_index:])
        if max_aqua == max_r:
            print(aqua[min_index:].index(max_aqua) + min_index + 1)
        else:
            print(min_index - aqua[:min_index][::-1].index(max_aqua))
