# http://codeforces.com/problemset/problem/753/A

def getSweets(sweetCount):
    if sweetCount == 1:
        return [1]

    sweetsList = []
    sumN = 0
    n = 1
    while sumN + n <= sweetCount:
        sumN += n
        sweetsList.append(n)
        n += 1

    sweetsList[-1] += sweetCount - sumN
    return sweetsList


if __name__ == '__main__':
    sweetCount = int(input())
    sweets = getSweets(sweetCount)
    sweets = list(map(str, sweets))

    print(len(sweets))
    print(' '.join(sweets))