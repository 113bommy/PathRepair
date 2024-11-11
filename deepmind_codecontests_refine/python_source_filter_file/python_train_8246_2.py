n = int(input())
s = input()
if n == 1:
    print(1)
    exit()

l = []
for i in s:
    l.append(ord(i)-97)

f = 1
while f:
    o = []
    m = -1
    d = -1
    i = 0
    f = 0
    if len(l) == 1:
        break

    while i < len(l):
        if i == 0:
            if l[i]-1 == l[i+1]:
                if l[i] > m:
                    f = 1
                    m = l[i]
                    d = i

            i = i + 1
            continue

        if i == len(l)-1:
            if l[i]-1 == l[i-1]:
                if l[i] > m:
                    f = 1
                    m = l[i]
                    d = i

            i = i+1
            continue

        if l[i]-1 == l[i-1] or l[i]-1 == l[i+1]:
            if l[i] > m:
                f = 1
                m = l[i]
                d = i

        i = i+1

    for i in range(len(l)):
        if i == d:
            continue

        o.append(l[i])

    l = o

print(n-len(l))