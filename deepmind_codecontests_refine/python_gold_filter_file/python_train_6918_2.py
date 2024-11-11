p = input()
p_lst = p.split()
Holiday = int(p_lst[0])
people = int(p_lst[1])
m = []
for i in range(Holiday):
    m.append(0)
for o in range(people):
    day = input()
    d_lst = day.split()
    d1 = int(d_lst[0]) - 1
    d2 = int(d_lst[1])
    for j in range(d1, d2):
        m[j] += 1
t = 1
for i in m:
    if i != 1:
        print(m.index(i) + 1, i)
        break
if m.count(1) == Holiday:
    print("OK")
