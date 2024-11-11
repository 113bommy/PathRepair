import bisect
a = int(input())
b = [int(input()) in d in range(a)]
c = [b[1]]
for i in b[1:]:
    if c[-1] < i:
        c.append(i)
    else:
        c[bisect.bisect_left(c,i)] = i
        
print(len(c))
