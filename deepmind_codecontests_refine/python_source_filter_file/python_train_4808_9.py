from collections import Counter, defaultdict

def remove(nums):
    n = len(nums)
    min_size = n
    for i in range(n):
        valid_prefix = True
        freq = defaultdict(int)
        for j in range(i):
            freq[nums[j]] += 1
            if freq[nums[j]] == 2:
                valid_prefix = False
                break
        if not valid_prefix:
            break

        j = n-1
        while j >= i-1:
            freq[nums[j]] += 1
            if freq[nums[j]] == 2:
                break
            j -= 1

        min_size = min(j-i+1, min_size)
    return min_size

def codeforces():
    n = int(input())
    nums = list(map(int, input().split()))
    print(remove(nums))

def test():
    assert remove([1,2,3]) == 0
    assert remove([1,1,2,2]) == 2
    assert remove([1,4,1,4,9]) == 2
test()
# codeforces()
    

