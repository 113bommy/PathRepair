def solution():
    from sys import stdout, stdin
    _input, _print = stdin.readline, stdout.write
    _int, _range, _min, _max = int, range, min, max
    for _ in _range(_int(_input())):
        n = _int(_input())
        arr = [_int(i) for i in _input().split()]
        t = [[0]*27 for i in _range(n)]
        t[0][arr[0]] += 1
        for i in _range(1,n):
            for j in _range(27):
                if j == arr[i]:
                    t[i][j] += t[i-1][j] + 1
                else:
                    t[i][j] = t[i-1][j]
        ans = 0
        for i in _range(n-1):
            for e in _range(i+1, n-1):
                right = [0, 0]
                right_v = [0, 0]
                mid = [0, 0]
                mid_v = [0, 0]
                for j in _range(27):
                    if mid[0] < t[e][j] - t[i][j]:
                        mid[1] = mid[0]
                        mid_v[1] = mid_v[0]
                        mid[0] = t[e][j] - t[i][j]
                        mid_v[0] = j
                    else:
                        if mid[1] < t[e][j] - t[i][j]:
                            mid[1] = t[e][j] - t[i][j]
                            mid_v[1] = j
                    temp = _min(t[-1][j]-t[e][j], t[i][j])
                    if temp > right[0]:
                        right[1] = right[0]
                        right_v[1] = right_v[0]
                        right[0] = temp
                        right_v[0] = j
                    else:
                        if temp > right[1]:
                            right[1] = temp
                            right_v[1] = j
                if right_v[0] != mid_v[0]:
                    if right[0]*2 + mid[0] > ans:
                        ans = right[0]*2 + mid[0]
                if right_v[1] != mid_v[0]:
                    if right[1]*2 + mid[0] > ans:
                        ans = right[1]*2 + mid[0]
                if right_v[0] != mid_v[1]:
                    if right[0]*2 + mid[1] > ans:
                        ans = right[0]*2 + mid[1]
                if right_v[1] != mid_v[1]:
                    if right[1]*2 + mid[1] > ans:
                        ans = right[1]*2 + mid[1]
        print(_max(ans, _max(t[-1])))
solution()
