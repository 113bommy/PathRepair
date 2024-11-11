t = int(input())
while t:
    t-=1
    s = input()
    l = []
    c = 0
    for i in s:
        if i == '1':
            c +=1
        elif i == '0' and c!=0:
            l.append(c)
            c = 0
    l.append(c)
    l.sort(reverse=True)
    alice = 0
    print(l)
    for i in range(len(l)):
        if i%2 == 0:
            alice += l[i]
    print(alice)

