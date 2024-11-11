total = 0
nums = []

def inp():
    global total, nums
    total = int(input())
    i = input()
    nums = i.split(' ')
    nums = [int(num) for num in nums]

def solve():
    global total, nums
    mid = int(total/2)
    rs = nums[:]
    for i in range(1, mid+1):
        if i % 2 != 0:
            rs[i-1] = nums[total - i]
            rs[total - i] = nums[i - 1]
            continue
        rs[i - 1] = nums[i - 1]
        rs[total - i] = nums[total - i]

    return rs

def printrs(rs):
    for i in range(len(rs)):
        if i == len(rs) - 1:
            print(rs[i])
            return
        print(rs[i], end=' ')

if __name__=='__main__':

    inp()
    rs = solve()
    print(printrs(rs))