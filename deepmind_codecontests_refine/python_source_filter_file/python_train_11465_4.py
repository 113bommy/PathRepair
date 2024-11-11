def solution():
    N = int(input())
    for i in range(N):
        d = int(input())
        if d**2 - 4*d < 0:
            print(N)
        else:
            x = (d**2 - 4*d) ** 0.5
            if x < 0:
                x = -x
            print('Y '+str((d+x) / 2) + ' ' + str((d-x) / 2))


solution()
