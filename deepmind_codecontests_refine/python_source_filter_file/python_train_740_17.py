from collections import Counter

def solve(n, nums):
    if n == 1:
        return False if len(nums) < 1 else [[nums.pop()]]

    counts = Counter(nums)
    if n % 2 == 0:
        keys = []
        for num, count in counts.items():
            if count >= 4 and count % 4 == 0:
                while count > 0:
                    keys.append(num)
                    count -= 4
            else:
                return False
        
        matrix = [None for _ in range(n)]

        for r in range(0, n//2):
            row = [0] * n
            for c in range(0, n//2):
                key = keys.pop()
                row[c] = key
                row[n-c-1] = key
            matrix[r] = row
            matrix[n-r-1] = row
        
        return matrix
    else:
        num_fours_needed = (n//2) * (n//2)
        keys = []
        for key, count in counts.items():
            while count >= 4 and len(keys) < num_fours_needed:
                keys.append(key)
                count -= 4
            
            counts[key] = count

            if len(keys) == num_fours_needed:
                break
        
        if len(keys) != num_fours_needed:
            return False

        count_nums = {1: [], 2:[]}

        for key, count in counts.items():
            while count >= 4:
                count_nums[2].append(key)
                count -= 2
            
            while count >= 2:
                count_nums[2].append(key)
                count -= 2

            if count != 0:
                count_nums[count].append(key)

        matrix = [[] for _ in range(n)]
        print(keys)
        print(num_fours_needed)
        for r in range(0, n//2):
            row = [0] * n
            for c in range(0, n//2):
                key = keys.pop()
                row[c] = key
                row[n-c-1] = key
            matrix[r] = row
            matrix[n-r-1] = row
        
        try:
            # Fill in middle row
            row = [0] * n
            matrix[n//2] = row
            #print(matrix)

            for i in range(0, n//2):
                key = count_nums[2].pop()
                row[i] = key
                row[n-i-1] = key
            
            row[n//2] = count_nums[1].pop()

            # Fill in middle column
            mid_col = n//2
            for i in range(0, n//2):
                key = count_nums[2].pop()
                matrix[i][mid_col] = key
                matrix[n-i-1][mid_col] = key
        except Exception as E:
            return False

        return matrix
        


        


            
n = int(input())
nums = list(map(int, input().split()))

res = solve(n, nums)

if res:
    print("YES")
    for r in res:
        print(*map(str, r))
else:
    print("NO")
