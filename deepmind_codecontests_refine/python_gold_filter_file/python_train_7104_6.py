numcases = int(input())
for i in range(numcases):
    n1, n2, n3 = map(int, input().split())
    ans = "0"
    if n2 != 0:
        if n1 + n3 != 0:
            for i in range(n1):
                ans = ans + '0'
            ans = ans + '1'
            for i in range((n2 - 1)//2):
                ans = ans + "01"
            for i in range(n3):
                ans = ans + "1"
            if n2%2 == 0:
                ans = ans + "0"
            print(ans)
        else:
            ans = "0"
            count = 0
            for i in range(n2):
                if count == 0:
                    ans = ans + "1"
                    count = 1
                else:
                    ans = ans + "0"
                    count = 0
            print(ans)
    else:
        if n1 == 0:
            ans = "1"*(n3 + 1)
        else:
            ans = "0"*(n1 + 1)
        print(ans)