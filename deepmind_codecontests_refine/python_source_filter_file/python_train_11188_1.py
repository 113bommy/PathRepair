n = input()

handles_dict = {}


i = 0
while i < int(n):
    change = input().split(' ')
    old = change[0]
    new = change[1]

    found = False
    j = 0
    while j < len(handles_dict):
        if old in handles_dict[j]:
            handles_dict[j].append(new)
            found = True
        j += 1

    if not found:
        handles_dict[len(handles_dict)] = [old, new]

    i += 1

print(len(handles_dict))
k = 0
while i < len(handles_dict):
    print("{0} {1}".format(handles_dict[i][0], handles_dict[i][-1]))
    k += 1

