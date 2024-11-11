import collections
n = int(input())
a = list(map(int, input().split()))
try:
    matrix = [[1]]
    for i in range(1, 12):
        matrix.append([4 for j in range(len(matrix[-1]))])
        matrix.append(sorted(matrix[-2] + [2, 2] + [4 for j in range(i*2 - 1)], reverse = True))
    nowmatrix = matrix[n-1]
    nowmatrix = collections.Counter(nowmatrix)
    nowmatrix = nowmatrix.most_common()
    matrix = []
    for i in range(len(nowmatrix)):
        matrix.append(list(nowmatrix[i]))
    matrix.sort(reverse=True)
    a = collections.Counter(a)
    a = a.most_common()
    alist = []
    for i in range(len(a)):
        alist.append(list(a[i]))
    ans = []
    for i in range(len(alist)):
        count = alist[i][1] // 4
        alist[i][1] -= 4*count
        ans += [alist[i][0] for j in range(count)]
    if n % 2 == 1:
        if len(ans) >= matrix[0][1]:
            ans += ans[matrix[0][1]:]
            for i in range(len(alist)):
                count = alist[i][1] // 2
                alist[i][1] -= 2*count
                ans += [alist[i][0] for j in range(count)]
            if len(ans) == matrix[0][1] + matrix[1][1]:
                for i in range(len(alist)):
                    count = alist[i][1]
                    alist[i][1] -= count
                    ans += [alist[i][0] for j in range(count)]
            else:
                ans = -1
        else:
            ans = -1
    else:
        if len(ans) != matrix[0][1]:
            ans = -1

    if n == 1:
        print("YES")
        print(alist[0][0])
    else:
        if ans == -1:
            print("NO")
        else:
            ansmatrix = [[0 for i in range(n)] for j in range(n)]
            count = 0
            for i in range(n//2):
                for j in range(n//2):
                    ansmatrix[i][j] = ans[count]
                    ansmatrix[n-1-i][n-1-j] = ans[count]
                    ansmatrix[n-1-i][j] = ans[count]
                    ansmatrix[i][n-1-j] = ans[count]
                    count += 1
            if n % 2 == 1:
                for i in range(n//2):
                    ansmatrix[n//2][i] = ans[count]
                    ansmatrix[n//2][n-1-i] = ans[count]
                    count += 1
                for i in range(n//2):
                    ansmatrix[i][n//2] = ans[count]
                    ansmatrix[n-1-i][n//2] = ans[count]
                    count += 1
                ansmatrix[n//2][n//2] = ans[count]
            print("YES")
            for i in range(len(ansmatrix)):
                print(' '.join(map(str, ansmatrix[i])))
except:
    print("NO")
