n = int(input())
numbers = list(map(int, input().split(" ")))
ls = [[numbers[0]]]
for i in range(1,n):
    flag = 0
    for j in range(0, len(ls)):
        if i not in ls[j]:
            ls[j].append(numbers[i])
            flag = 1
            break
    if flag == 0:
        ls.append([numbers[i]])
print(len(ls))