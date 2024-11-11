def crosses(lst):
    count = 0
    for i in range(1, len(lst)):
        for j in range(1, len(lst)):
            if i + 1 < len(lst) and j + 1 < len(lst):
                count += lst[i][j] == 'X' and lst[i - 1][j - 1] == 'X' and lst[i - 1][j + 1] == 'X' and lst[i + 1][
                    j - 1] == 'X' and lst[i + 1][j + 1] == 'X'
    return count


n = int(input())
a = list()
for i in range(n):
    s = input()
    a.append(list(s))
print(crosses(a))
