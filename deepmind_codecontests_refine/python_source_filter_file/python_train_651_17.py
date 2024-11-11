for _ in range(int(input())):
    n = int(input())
    evens = [x for x in range(4, 401) if x % 2 == 0]
    cur = []
    for num in evens:
        flag = True
        for elem in cur:
            if num % elem == 0:
                flag = False
        if flag:
            cur.append(num)
    print(*cur[:n])