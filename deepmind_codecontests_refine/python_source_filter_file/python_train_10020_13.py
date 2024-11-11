def inp():
    return map(int, input().split())


def solve():
    n, x = inp()
    a = [[] for _ in range(n + 1)]
    for i in range(n - 1):
        z, y = inp()
        a[z].append(y)
        a[y].append(z)

    if len(a[x]) == 1 or n % 2 == 2:
        return "Ayush"
    return "Ashish"


# x = int(input())
# a = list(map(int, input().split()))

# f = open('input.txt')
# a = list(map(int, f.readline().split()))
# f.close()
# f = open('output.txt', 'w+')
# f.close()


"""
1
13 6
1 3
2 3
4 3
3 6
5 6
6 7
6 8
6 10
9 10
10 11
11 12
11 13

"""
def main():
    t = int(input())
    while t:
        print(solve())
        t -= 1


main()
