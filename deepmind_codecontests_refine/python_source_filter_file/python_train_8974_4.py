if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        a = [-1 if i == 1 else 1 for i in a]
        tsum = sum(a)
        lefta = a[ : len(a) // 2]
        righta = a[len(a) // 2 : ]
        lefta = lefta[ : : -1]
        lsums = {}
        rsums = {}

        csum = 0
        for i in range(len(lefta)):
            csum += lefta[i]
            if csum not in lsums:
                lsums[csum] = i + 1
        
        csum = 0
        for i in range(len(righta)):
            csum += righta[i]
            if csum not in rsums:
                rsums[csum] = i + 1
        
        ans = 0
        if tsum != 0:
            ans = float("inf")
            csum = 0
            for i in range(len(righta)):
                csum += righta[i]
                cntrsum = tsum - csum
                if cntrsum in lsums:
                    ans = min(ans, lsums[cntrsum] + i + 1)
                if csum == tsum:
                    ans = min(ans, i + 1)
            csum = 0
            for i in range(len(lefta)):
                # csum += lefta[i]
                # cntrsum = tsum - csum
                # if cntrsum in rsums:
                #     ans = min(ans, rsums[cntrsum] + i + 1)
                if csum == tsum:
                    ans = min(ans, i + 1)
        
        print(ans)