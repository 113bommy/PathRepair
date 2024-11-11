

def magic():
    num_of_opened, indices_of_opened = 0, []
    for i, char in enumerate(input()):
        if char == '(':
            indices_of_opened.append(i)
        elif indices_of_opened:
            yield indices_of_opened.pop()
            yield i

def solve():
    group, prev = 0, 0
    maxgroup, maxgroupcount = 0, 0
    for index in set(magic()):
        sub = index - prev
        if sub == 1 or sub == index:
            group += 1
        elif group > 0:
            if maxgroup == group: maxgroupcount += 1
            if maxgroup < group:
                maxgroup = group
                maxgroupcount = 1
            group = 1
        prev = index

    if maxgroup < group:
        maxgroup = group
        maxgroupcount = 1
    elif maxgroup == group:
        maxgroupcount += 1

    return "%s %s" % (maxgroup, maxgroupcount)


print(solve())

