n, s = map(int, input().split())
forward_stations = list(map(lambda x: int(x) == 1, input().split()))
backward_stations = list(map(lambda x: int(x) == 1, input().split()))

if forward_stations[0]:
    if forward_stations[s-1] or s == 1:
        print("YES")
    elif not backward_stations[s-1]:
        print("NO")
    else:
        done = False
        for i in range(s-1, n):
            if backward_stations[i] and forward_stations[i]:
                print("YES")
                done = True
                break

        if not done:
            print("NO")
else:
    print("NO")
