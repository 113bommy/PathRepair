

if __name__ == "__main__":
    q = int(input())
    # print("q")

    while q > 0:
        q -= 1

        n = int(input())
        # print("n")
        robots = []
        for i in range(n):
            robot = list(map(int, input().split()))
            robots.append(robot)
        
        inf = float("inf")

        xmax = inf
        xmin = -inf
        ymax = inf
        ymin = -inf

        possible = True

        for robot in robots:
            x, y = robot[0 : 2]
            dirs = robot[2 : ]
            _xmin = -inf
            _xmax = inf
            _ymin = -inf
            _ymax = inf

            if dirs[0] == 0:
                _xmin = x
            if dirs[1] == 0:
                _ymax = y
            if dirs[2] == 0:
                _xmax = x
            if dirs[3] == 0:
                _ymin = y
            
            xmax = min(xmax, _xmax)
            ymax = min(ymax, _ymax)
            xmin = max(xmin, _xmin)
            ymin = min(ymin, _ymin)

            if not(xmin <= xmax and ymin <= ymax):
                possible = False
    
        if possible:
            print(1, min(xmax, int(1e5)), min(ymax, int(1e5)))
        else:
            print(0)