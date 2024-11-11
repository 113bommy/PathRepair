alist = input().split()
sumofa = 0
for i in range(len(alist)):
    alist[i] = int(alist[i])
    sumofa = sumofa + alist[i]
    
true = 0
for x in range(len(alist)):
    if alist[x] == (sumofa/2):
        print("YES")
        break
else:
    for i in range(1,4):
        if alist[0] + alist[i] == sumofa/2:
            true = 1

    if true == 1:
        print("YES")
    else:
        print("NO")