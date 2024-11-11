a = int(input())
for x in range(a):
    b, c, d, e = map(int, input().split())
    f = list(map(int, input().split()))
    f.sort()
    if d == e:
        print(0)
    else:
        if d > e:
            h = b - e - 1
            g = abs(d-e)-1
            l = 0
            t = 0
            for y in range(c):
                if f[y] > h or g == 0:
                    break
                else:
                    t += 1
                    g -= 1
            if t <= 0:
                print(0)
            else:
                for y in range(t-1, -1, -1):
                    if f[y] > h:
                        continue
                    else:
                        l += 1
                        h -= 1

                print(l)

        else:
            h = e - 1 - 1
            g =abs(d-e-1)
            l = 0
            t = 0
            for y in range(c):
                if f[y] > h or g == 0:
                    break
                else:
                    t += 1
                    g -= 1
            if t <= 0:
                print(0)
            else:
                for y in range(t - 1, -1, -1):
                    if f[y] > h:
                        continue
                    else:
                        l += 1
                        h -= 1

                print(l)



