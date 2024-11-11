input()
lists = map(int, input().split())
lists = list(sorted(set(lists)))
if len(lists) > 3:
    for i in range(len(lists) - 2):
        if lists[i+2] - lists[i] == 2:
            print('yes')
            exit()
print('no')
