n = input()
for i in range(int(n)):
    s = input()
    t = input()
    p = input()
    counter = 0
    load = []
    for k in list(t):
        if (counter < len(s)):
            if (s[counter] == k):
                counter += 1
            else:
                load.append(k)
        else:
            load.append(k)
    check = True
    if (counter == 0):
        check = False
    load = sorted(load)
    for k in range(len(list(load))):
        if (check):
            if (load.count(load[k]) <= p.count(load[k])):
                k += load.count(load[k]) - 1
            else:
                check = False
        else:
            break
    if(check):
        print("YES")
    else:
        print("NO")

