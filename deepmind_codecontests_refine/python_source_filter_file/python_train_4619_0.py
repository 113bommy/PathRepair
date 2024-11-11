n = int(input())
solution = 0
i=1
while i >= n:
    num = str(input())
    if num.count('1') >= 2:
        solution += 1
        i+=1
    else:
        i+=1

print(solution)


