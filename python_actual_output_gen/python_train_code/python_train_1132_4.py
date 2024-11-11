def cunstructNum(l, m):
    return sum([(m*10)**x for x in range(0, l+1)])
def countBeautiful(k):
    num = int(k)
    if num < 10:
        print(num)
        return
    if num == 0:
        print(0)
    base = (len(k) - 1) * 9
    add = 0
    if num >= cunstructNum(len(k)-1, int(k[0])):
        add = int(k[0])
    else:
        add = int(k[0])-1
    print(add+base)

for i in range(int(input())):
    countBeautiful(input())