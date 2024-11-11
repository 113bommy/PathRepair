l = list(set(list(map(int, input().split(',')))))
output = ''
cur = l[0]
for i in range(1, len(l) + 1):
    if i == len(l) or l[i] - l[i - 1] > 1:
        if output is not '':
            output += ','
        if l[i - 1] == cur:
            output += str(l[i - 1])
        else:
            output += str(cur) + '-' + str(l[i - 1])
        if i is not len(l):
            cur = l[i]
print(output)