n = int(input())
nums = []
for i in range(n):
    inp = input().split()
    inp[0], inp[1], inp[2] = int(inp[0]), int(inp[1]), int(inp[2])
    if inp[0] + inp[1] + inp[2] % 2 is 1:
        nums.append((inp[0] + inp[1] + inp[2] - 1)//2)
    else:
        nums.append(int((inp[0] + inp[1] + inp[2])//2))
for i in range(n):
    print(nums[i])
    
    
