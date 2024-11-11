lines = [tuple(input().split()) for i in range(8)]
x_set = set()
y_set = set()

for x, y in lines:
    x_set.add(x)
    y_set.add(y)

if len(x_set) == len(y_set) == 3:
    flag = False
    x_sort, y_sort = sorted(x_set), sorted(y_set)
    for x in x_sort:
        for y in y_sort:
            if(x, y) != (x_sort[1], y_sort[1]) and (x, y)not in lines:
                flag = True

else:
    flag = True

print ("ugly" if flag else "respectable")
