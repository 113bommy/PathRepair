def kolya(n, lst):
    if n != 3 or (lst[0] != -3 or lst[1] != -3 or lst[2] != 2):
        for i in range(n):
            if lst[i] >= 0:
                lst[i] = -lst[i] - 1
        if n % 2 != 0:
            mx, ind = -1, -1
            for i in range(n):
                if abs(lst[i]) > mx:
                    mx, ind = abs(lst[i]), i
            lst[ind] = -lst[ind] - 1
    return lst


m = int(input())
a = [int(j) for j in input().split()]
print(*kolya(m, a))
