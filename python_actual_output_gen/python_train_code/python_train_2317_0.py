def recursion(a):
    summ = 0
    for j in range(0, a + 1):
        summ += j
    return summ
n = int(input())
for i in range(n):
    i = input()
    print(recursion(4 * (int(i) % 10 - 1)) + recursion(len(i)))