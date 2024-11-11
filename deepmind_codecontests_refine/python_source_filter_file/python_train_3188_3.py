def nulls(n):
    data = list(str(n))
    iter = 0
    for i in range(len(data)-1,-1,-1):
        if data[i] != 0:
            break
        iter+=1
    return iter
def sol():
    n,am = list(map(int,input().split()))
    if am == 0:
        print(n)
        return 0
    deviders = [n]
    iter = 2
    while iter*iter <= n:
        if iter*iter != n:
            if n%iter == 0:
                deviders.append(iter)
                deviders.append(n//iter)
        else:
            if n%iter == 0:
                deviders.append(iter)
        iter+=1
    vars = []
    for i in range(len(deviders)):
        nullsEnd = nulls(deviders[i])
        number = int(str(deviders[i]) + "0"*max(0,(am-nullsEnd)))
        if number%n == 0:
            vars.append(number)
    print(min(vars))
sol()
