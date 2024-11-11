flag = False
cli = [0] * 1000
sen = set()
kon = set()
while True:
    try:
        c, d = map(int, input().split(","))
    except:
        if flag:
            break
        flag = True
        continue
    if flag:
        kon.add(c)
    else:
        sen.add(c)
    cli[c] += 1

for i in range(1,1001):
    if i in sen and i in kon:
        print(i,cli[i])