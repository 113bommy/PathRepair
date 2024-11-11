#!/usr/bin/python3


def main():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    if m<n:
        for i in range(m):
            print(0, end='')
    else:
        if n == 1:
            for t in range(0, m):
                print(1, end='')
            return
        lenArr = len(arr)
        countArr = [0]*(n+1)
        indexArr = [[] for i in range(0, n+1)]

        for j in range(0, lenArr):
            countArr[arr[j]] += 1
            indexArr[arr[j]].append(j)

        minlen = min(countArr[1:])

        res = []
        for y in range(0, minlen):
            tmpArr = set()
            for z in indexArr[1:]:
                tmpArr.add(z[y])
            res.append(max(tmpArr))

        result = ['0']*m

        for k in range(0, m):
            result[k] = '1'

        result = ''.join(result)
        print(result)


if __name__ == "__main__":
    main()
