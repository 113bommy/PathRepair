for _ in range(int(input())):
    n, m = map(int, input().split())
    data = list(map(int, input().split()))
    for index, value in enumerate(data[1:]):
        index += 1
        potential = m // index
        if potential == 0:
            break
        incr = min(potential, value)
        data[0] += incr 
        m = m - incr * index
    print(data[0])
