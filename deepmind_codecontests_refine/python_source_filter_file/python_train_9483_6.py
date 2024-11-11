"""
Your module description
"""
nm = input().split(' ')
n = int(nm[0])
m = int(nm[1])

c = input().split(' ')
a = input().split(' ')
i = 0
j = 0
for x in a :
    if j < len(c) :
        for y in range(j,len(c)) :
            if int(x)>=int(c[y]) :
                j = y+1
                i += 1
                break
            else :
                j = y
print(i)