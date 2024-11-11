n = int(input())
Result = []
for i in range(0,n):
    num = int(input())

    if num % 2 == 0:
        if num > 2 :
            Result.append(int(num/4))
        else:
            Result.append(-1)
    else:
        if num >= 13 or num == 9:
            Result.append(int((num - 9)/4) + 1)
        else:
            Result.append(-1)
for i in Result:
    print(i)