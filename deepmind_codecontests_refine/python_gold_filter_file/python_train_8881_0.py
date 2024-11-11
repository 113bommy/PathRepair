t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if sum(a) != sum(b):
        print(-1)
    else:
        s = 0
        for i in range(n):
            s += abs(a[i] - b[i])
        print(s // 2)

        for i in range(n):
            if a[i] < b[i]:
                while a[i] != b[i]:
                    for j in range(i + 1, n):
                        if a[i] == b[i]:
                            break

                        if a[j] >= 0 and a[j] > b[j]:
                            print(j+1, i+1)
                            a[j] -= 1
                            a[i] += 1
            else:
                while a[i] != b[i]:
                    for j in range(i + 1, n):
                        if a[i] == b[i]:
                            break

                        if a[j] < b[j]:
                            print(i+1, j+1)
                            a[j] += 1
                            a[i] -= 1

