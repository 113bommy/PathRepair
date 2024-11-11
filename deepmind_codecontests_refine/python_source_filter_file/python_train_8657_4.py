import copy 

def check(nums,index,d):
    new = copy.deepcopy(nums)
    new.pop(index)
    for i in range(1,len(new)):
        if new[i][0]-new[i-1][0] != d:
            return False

    return True

def main():
    n = int(input())
    nums = list(map(int,input().split()))
    if n <= 3:
        print(1)
        return
    nums1 = []
    for i in range(n):
        nums1.append([nums[i],i+1])
    nums1.sort()
    nums = nums1
    d_count = {}

    for i in range(1,n):
        d1 = nums[i][0]-nums[i-1][0]
        if d1 not in d_count.keys():
            d_count[d1] = 1
        else:
            d_count[d1] += 1


    if len(d_count) > 3:
        print(-1)
        return
    if len(d_count) == 1:
        nums[0][1]
        return

    max_count = 0
    d = 0
    for i in d_count.keys():
        if d_count[i] > max_count:
            max_count = d_count[i]
            d = i

    for i in d_count.keys():
        if d_count[i] == max_count:
            d = max(d,i)

    index = -1
    for i in range(1,n):
        d1 = nums[i][0]-nums[i-1][0]
        if d1 != d:
            if index != -1:
                print(-1)
                return
            #print(d1)
            if check(nums,i,d):
                index = nums[i][1]
                if i+1 < len(nums):
                    nums[i][0] = nums[i+1][0]-d
            elif check(nums,i-1,d):
                index = nums[i-1][1]
            else:
                print(-1)
                return            
           
    print(index)
    

main()
