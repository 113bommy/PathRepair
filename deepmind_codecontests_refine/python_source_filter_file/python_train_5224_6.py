n = int(input())
a = [i for i in input()]
result = [0,0,0,0,0,0,0,0,0,0]
for _ in a:
    if _ == 'L':
        for i in range(0,5):
            if result[i] != 1:
                result[i] += 1
                break
    elif _ == 'R':
        for j in range(9,4, -1):
            if result[j] !=1:
                result[j] += 1
                break
    else:
        b = int(_)
        result[b] -=1
print("".join(map(str,result)))
