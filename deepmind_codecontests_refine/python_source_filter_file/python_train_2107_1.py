# from sys import stdout, stdin

# read = stdin.readline
# write = stdout.write

t = int(input())

for _ in range(t):
    n = int(input())
    animals = [int(d) for d in input().split()]
    same = True
    if n % 2 == 0:
        for i in range(1, n):
            if animals[i] != animals[i-1]:
                same = False
                break
        if not same:
            print(2)
            print(*([1, 2] * (n//2)))
        else:
            print(1)
            print([1] * n)
    else:
        clr_num = 1
        clr = {1: 2, 2: 1}
        colors = [1] * n
        same = True
        need_stay = False

        if animals[-1] != animals[0]:
            need_stay = True

        for i in range(1, n):
            if animals[i] == animals[i-1]:
                if need_stay:
                    need_stay = False
                    colors[i] = colors[i-1]
                else:
                    colors[i] = clr[colors[i-1]]
            else:
                same = False
                clr_num = 2
                colors[i] = clr[colors[i-1]]

        if animals[-1] != animals[0] and colors[-1] == colors[0]:
            colors[-1] = 3
            clr_num = 3
        if not same:
            print(clr_num)
            print(*colors)
        else:
            print(1)
            print(*([1] * n))



        
        
        


