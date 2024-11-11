def solve(n, ll):
    nums = [0] * 3001
    dup = []
    for i in ll:
        if nums[i] == 1:
            dup.append(i)
        else:
            nums[i] = 1
    dup.sort()
    coins = 0
    for i in dup:
        right = i + 1
        while right < 3001:
            if nums[right] == 0:
                coins += abs(i - right)
                nums[right] = 1
                break
            right += 1
    return coins

n = int(input())
ll = list(map(int,input().split()))
print(solve(n, ll))
