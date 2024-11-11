class Solution(object):
    def run(self):
        n, m = [int(x) for x in input().split()]
        if n > m:
            n, m = m, n
        res = (n * m) // 2
        if n == 1 and (m + 1) % 6 / 3:
            res -= 1
        elif n == 2:
            if m == 2:
                res = 0
            elif m == 3:
                res = 2
            elif m == 7:
                res = 6
        print(res * 2)

if __name__ == '__main__':
    Solution().run()