in_nums = input().split()
  
num_posts = int(in_nums[0])
k = int(in_nums[1])
heights = [int(x) for x in input().split()]

current_sum = sum(heights[:k])
current_min = current_sum
min_idx = 0

for n in range(1, num_posts - k + 1):
    
    current_sum += (-1 * heights[n-1] + heights[n + k -1])
    
    if current_sum < current_min:
        current_min = current_sum
        min_idx= n

print(min_idx + 1)

