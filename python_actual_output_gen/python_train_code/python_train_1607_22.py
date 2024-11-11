n = int(input())
solution = 0
for i in range(1,n):
    num = str(input())
    if num.count('1') >= 2:
        solution += 1
        i+=1
    else:
        i+=1

print(solution)


