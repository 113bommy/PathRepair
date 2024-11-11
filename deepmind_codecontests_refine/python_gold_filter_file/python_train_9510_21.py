def main():
    n = int(input())
    nums = list(map(int, input().split(' ')))
    min_i = 0
    for i, num in enumerate(nums):
        if num < nums[min_i]:
            min_i = i
    found = False
    for i, num in enumerate(nums):
        if num == nums[min_i]:
            if found:
                return None
            found = True
        
    return min_i + 1


x = main()
if x:
    print(x)
else:
    print("Still Rozdil")
