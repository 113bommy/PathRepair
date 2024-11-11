a = input().split(" ")
a = [int(e) for e in a]
capacity = a[1]


l = input().split(" ")
l = [int(e) for e in l]

assert a[0] == len(l)


min_num = 0
max_num = 0
num = 0

for change in l:
    num += change
    if min_num == None or num < min_num:
        min_num = num
    if max_num == None or num > max_num:
        max_num = num

print(capacity - max_num + min_num + 1)


