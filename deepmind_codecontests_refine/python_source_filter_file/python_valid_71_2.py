for _ in range(int(input())):
    n, m = map(int, input().split())
    if(m == 1):
        s = str(n)
        if(n <= int(s[0] * len(s))):
            print(int(s[0] * len(s)))
        else:
            int(str(int(s[0]) + 1) * len(s))
    else:
        A = list(str(n))
        if(min(A) == max(A)):
            print(n)
        else:
            x = -1
            s = str(n)
            for i in range(len(A) - 1):
                if(A[i] != A[i + 1]):
                    x = i + 1
                    break
            if(n <= int(s[:x + 1] + str(max(int(s[x]), int(s[x - 1]))) * (len(s) - x - 1))):
                #print(int(s[:x + 1] + str(max(int(s[x]), int(s[x - 1]))) * (len(s) - x - 1)))
                Ans = s[:x + 1]
                mi = str(min(int(s[x]), int(s[x - 1])))
                ma = str(max(int(s[x]), int(s[x - 1])))
                for i in range(x + 1, len(s)):
                    if(int(Ans + mi + ma * (len(s) - i - 1)) >= n):
                        Ans += mi
                    else:
                        Ans += ma
                print(Ans)
            else:
                if(int(s[x]) + 1 == int(s[0])):
                    print(int(s[:x] + str(int(s[x]) + 1) + '0' * (len(s) - x - 1)))
                else:
                    print(int(s[:x] + str(int(s[x]) + 1) + str(min(int(s[x]) + 1, int(s[x - 1]))) * (len(s) - x - 1)))