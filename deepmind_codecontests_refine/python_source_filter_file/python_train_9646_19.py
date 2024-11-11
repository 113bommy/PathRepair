from math import sqrt

a = input()

n = int(a)
for i in reversed([str(i*i) for i in range(int(sqrt(n))+1)]):
    a_index = 0
    find_part = None
    for c in i:
        index = a.find(c, a_index)
        if index == -1:
            break
        else:
            a_index = index+1
    else:
        print(len(a) - len(i))
        exit()
print(-1)
