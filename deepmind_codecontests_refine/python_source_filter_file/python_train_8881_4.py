t = int(input())
for i in range(t):
    n =int(input())
    a = [int(x) for x in input().split()]
    b = [int(y) for y in input().split()]
    if sum(a) != sum(b):
        print(-1)
    else:
        if a == b:
            print(0)
        else:
            m = 0
            pos = []
            neg = []
            for i in range(n):
                m = m + abs(a[i] - b[i])
                if a[i] - b[i] > 0:
                    for j in range(a[i] - b[i]):
                        pos.append(i+1)
                elif a[i] - b[i] < 0:
                    for j in range(b[i] - a[i]):
                        neg.append(i+1)

            print(m/2)
            for h in range(len(pos)):
                print(pos[h], neg[h])

   
    