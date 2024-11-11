for _ in range(int(input())):
    n = int(input())
    data = [int(i) for i in input().split()]
    f = data.index(1) - n
    good = True
    if data[f] < data[f+1]:
        for i in range(n):
            if data[f+i] != i+1:
                good = False
                break
    else:
        f += n
        for i in range(n):
            if data[f - i] != i+1:
                good = False
                break
    if good:
        print("YES")
    else:
        print("NO")
