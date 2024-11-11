Figures = {"A": [[0, 1], [1, 0], [1, 1]],
           "B": [[1, 0], [2, 0], [3, 0]],
           "C": [[0, 1], [0, 2], [0, 3]],
           "D": [[1, -1], [1, 0], [2, -1]],
           "E": [[0, 1], [1, 1], [1, 2]],
           "F": [[1, 0], [1, 1], [2, 1]],
           "G": [[1, 0], [1, -1], [1, 0]]}
while True:
    try:
        k = [map(int, list(input())) for i in range(8)]
        l = [[y, x] for y,q in enumerate(k) for x,t in enumerate(q) if t]
        a, b = l[0]
        for i in range(4):
            l[i][0] -= a
            l[i][1] -= b
        for k, v in Figures.items():
            if l[1:] == v:
                print(k)
                break
        input()
    except:
        break