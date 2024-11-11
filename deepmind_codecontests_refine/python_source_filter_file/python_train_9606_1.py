for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    aux = [0] * 29
    for i in arr:
        for j in range(29):
            if 2**j > i:
                aux[j-1] += 1
                break
    count = 0
    for j in aux:
        count += j*(j-1)/2
    print(int(count))
