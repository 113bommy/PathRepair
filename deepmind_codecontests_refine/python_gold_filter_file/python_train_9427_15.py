n, k = list( map( int, input().split() ) )
passwords = []
for i in range(n):
    passwords.append(input())
correct = input()
# shorter is the number of shorter passwords, all of which will be tried before the correct one
# same is the number of same length passeords, which will be tried in worst case only
shorter, same = 0, 0
for p in passwords:
    if len(p) < len(correct):
        shorter = shorter + 1
    elif len(p) == len(correct):
        same = same + 1
    else:
        pass
# case where there is no shorter password than the correct password
if shorter == 0:
    # shorter = 1
    # print("1", 1+ same + 5*(same)//k)
    same = same + shorter + 5*((same+shorter-1)//k)
    shorter = shorter + 1
    print(shorter, same)
    exit (0)
if shorter < k-1:
    # shorter = shorter + 1
    same = same + shorter + 5*((same+shorter-1)//k)
    shorter = shorter + 1
    print(shorter, same)
    exit(0)
# print(shorter, same)
# now same will be used as the number of tries in worst case
# now shorter will be used as the number of tries in best case
same = same + shorter + 5*((same+shorter-1)//k)
# now shorter will be the cost of best case
# now same will be the cost of worst case
shorter = 1 + shorter + 5*(shorter//k)
print(shorter,same)
exit(0)