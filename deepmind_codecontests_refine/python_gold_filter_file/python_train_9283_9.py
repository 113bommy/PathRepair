n = int(input())
if n%2 != 0:
    print("YES")
    if n == 1:
        print("1 2")
    else:
        tab = [0 for i in range(n*2)]
        tab[0] = 1
        tab[n-1] = 3
        tab[n] = 2
        tab[2*n -1] = 4
        leftNum = 6
        rightNum = 10
        for i in range(1,(n//2)+1):
            tab[i] = leftNum
            tab[i + n] = leftNum + 1 if leftNum%2 == 1 else leftNum - 1
            if leftNum % 2 == 0:
                leftNum += 1
            else:
                leftNum += 7
        for i in range(n-2,n//2,-1):
            tab[i] = rightNum
            tab[i + n] = rightNum + 1 if rightNum % 2 == 1 else rightNum - 1
            if rightNum % 2 == 0:
                rightNum += 1
            else:
                rightNum += 7
        ret = ""
        for num in tab:
            ret += str(num) + " "
        print(ret)

else:
    print("NO")
