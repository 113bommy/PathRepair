import collections
class solution:
    def ans(n):
        count = 0
        for i in range(int(n)+1,9000):
            if len(set(str(i))) == len(str(n)) and count < 1:
                count += 1
                return i




n = str(input())
res = solution.ans(n)
print(res)
