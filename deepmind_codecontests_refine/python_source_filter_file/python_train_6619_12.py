import sys

a = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
# your code goes here
table = set([])
lenTabel = 0
for sock in arr:
    # print(table)
    if sock in table:
        table.remove(sock)
    else:
        table.add(sock)
        print(table)
        print("{} ini panjang".format(len(table)))
        lenTabel = len(table) if (len(table) > lenTabel) else lenTabel
print(lenTabel)
