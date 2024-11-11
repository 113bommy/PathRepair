n = int(input())
a = [int(i) for i in input().split()]
action = 0
rest = 0
for i in range(n):
    if a[i] == 0:
        rest += 1
        action = 0
    elif a[i] == 1:
        if action != 1:
            action = 1
        else:
            rest += 1
            action = 0
    elif a[i] == 2:
        if action != 2:
            action = 2
        else:
            rest += 1
            action = 0
    else:
        if action == 1:
            action = 2
        elif action == 2:
            action = 1
        else:
            j = i + 1
            while j < n and a[j] == 3:
                j += 1
            print(j, i, ((j - i) % 2) + a[j])
            if j != n:
                if ((j - i) % 2) + a[j] == 2:
                    action = 2
                else:
                    action = 1
print(rest)
