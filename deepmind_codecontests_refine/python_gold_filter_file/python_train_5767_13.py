# Lang: pypy3.6-v7.1.0-win32\pypy3.exe
# Problem Name: Sail
# Problem Serial No: 298
# Problem Type: B
# Problem Url: https://codeforces.com/problemset/problem/298/B 
# Solution Generated at: 2019-10-18 19:15:59.114324 UTC


t, sx, sy, ex, ey = map(int, input().split())
wind = input()
# base case when co ordinates are equal
if sx == ex and sy == ey:
    print(0)

else:
    t = 0

    for dir_ in wind:
        # we are taking optimal decision at each step
        if sx > ex and dir_ == "W":
            # we need to decrease sx and W => (x-1, y)
            sx -= 1
        elif sx < ex and dir_ == "E":
            # we need to increase sx E => (x+1, y)
            sx += 1
        elif sy > ey and dir_ == "S":
            sy -= 1
        elif sy < ey and dir_ == "N":
            sy += 1
        t += 1

        if sx == ex and sy == ey:
            print(t)
            exit()
    print(-1)

# Accepted
