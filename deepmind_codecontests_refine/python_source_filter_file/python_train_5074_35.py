class Solution(object):
    def __init__(self):
        pass
    
    def cutting(self, arr, b):
        acc = [0]
        for i in arr:
            acc.append(acc[-1] + (i & 1))
        ls = []
        n = len(arr)
        for i in range(0, n - 1):
            if (i + 1) % 2 == 0 and acc[i + 1] * 2 == i + 1 and 2 * (acc[n] - acc[i + 1]) == n - i - 1:
                ls.append(abs(arr[i + 1] - arr[i])) 
        ls.sort()

        c = 0
        for i in ls:
            b -= ls[0]
            if b < 0:
                break
            c += 1
        return c
            
    def _cutting(self, arr, b):
        self.acc = [0]
        for i in arr:
            self.acc.append(self.acc[-1] + (i & 1))
        return self.best(0, len(arr) - 1, b, arr, {})

    def check(self, i, j):
        n = self.acc[j] - self.acc[i - 1]
        return 2 * n == j - i + 1

    def best(self, i, j, b, arr, tb):
        
        if b < 0 or i == j or ((j - i + 1) & 1) != 0:
            return -(1 << 31) 

        if (i, j, b) in tb:
            return tb[(i, j, b)]

        sl = -(1 << 31) 
        for k in range(i + 1, j):
            n_b = b - abs(arr[k + 1] - arr[k])
            for l in range(0, n_b + 1):
                rs = self.best(i, k, l, arr, tb) + self.best(k + 1, j, n_b - l, arr, tb)
                if rs > 0 and sl < rs:
                    sl = rs

        if self.check(i + 1, j + 1) and sl <= 0:
            sl = 1
        tb[(i, j, b)] = sl
        return sl

def main():
    p = [int(e) for e in input().split()]
    arr = [int(e) for e in input().split()]
    sol = Solution()
    sets = sol.cutting(arr, p[1])
    if sets <= 0:
        print('0')
    else:
        print(sets)
    return 0


if __name__ == "__main__":
    main()