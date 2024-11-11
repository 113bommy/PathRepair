for x in range(int(input())):
    k = list(map(int, input().split()))
    n = list(map(int, input().split()))
    n.sort()
    counter = 0
    for i in range(1, len(n)):
        counter += (k[0]-n[i])//n[0]
    print(counter)