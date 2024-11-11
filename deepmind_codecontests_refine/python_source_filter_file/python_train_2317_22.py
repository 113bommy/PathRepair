t = int(input())

for _ in range(t):
    n = int(input())
    mass = [int(i) for i in input().split()]
    b = []
    k = 0
    for i in range(len(mass)):
        if i % 2:
            b.append(i+1)
            k += 1
        if k // 2 == n-1:
            for j in range(0, len(b)-1, 2):
                print(b[j], b[j+1])
            break
    else:
        if k % 2:
            b.pop()
            k -= 1
        i = 0
        while k // 2 != n-1:
            if mass[i] % 2 == 0:
                b.append(i)
                k += 1
            i += 1
        for j in range(0, len(b)-1, 2):
            print(b[j], b[j + 1])

