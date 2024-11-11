n = int(input())
ar = [int(i) for i in input().split()]

if n == 1:
    print(1)
    exit()

if ar[1] > ar[0]:
    li = [1]
elif ar[1] < ar[0]:
    li = [5]
else:
    li = [3]

c = 1
while c != n:
    j = 0

    if ar[c] > ar[c - 1]:
        while c != n and ar[c] > ar[c - 1]:
            c += 1
            j += 1
        for i in range(j-1):
            li.append(li[-1] + 1)
            if li[-1] == 6:
                print(-1)
#                print(*li)
                exit()
        if c != n and ar[c] == ar[c - 1]:
            li.append(li[-1] + 1)
        else:
            li.append(5)

    elif ar[c] < ar[c - 1]:
        while c != n and ar[c] < ar[c - 1]:
            c += 1
            j += 1
        for i in range(j-1):
            li.append(li[-1] - 1)
            if li[-1] == 0:
                print(-1)
 #               print(*li)
                exit()
        if c != n and ar[c] == ar[c - 1]:
            li.append(li[-1] - 1)
        else:
            li.append(1)

    else:
        while c != n and ar[c] == ar[c - 1]:
            c += 1
            j += 1
        for i in range(j):
            if li[-1] > 3:
                li.append(li[-1] - 1)
            else:
                li.append(li[-1] + 1)
        if c != n and ar[c] > ar[c - 1]:
            if li[-2] == 1:
                li[-1] = 2
            else:
                li[-1] = 1
        elif c != n and ar[c] < ar[c - 1]:
            if li[-2] == 5:
                li[-1] = 4
            else:
                li[-1] = 5

#print(c)
if max(li) > 5 or min(li) < 1:
    print(-1)
else:
    print(*li)
