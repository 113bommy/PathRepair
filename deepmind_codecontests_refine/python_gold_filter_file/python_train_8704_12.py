def solve():

    n = int(input())
    n = str(n)

    if n == n[::-1]:
        return "YES"

    count = 0
    for i in range(len(n)-1, 0, -1):
        if n[i] == '0':
            count += 1
        else:
            break

    # print(count, count*'0' + n)
    if count*'0' + n == n[::-1] + count*'0':
        return "YES"

    return "NO"

print(solve())