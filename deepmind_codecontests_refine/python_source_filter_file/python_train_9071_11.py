import bisect,math
left,right = map(int,input().strip().split())
if left == 1 and right == 1:
    print(1)
else:
    
    to_mod = 1000000007 
    ans = 0
    range_list = [1,2]
    left_num = [1,2]
    temp = 4
    while temp < right:
        range_list.append(temp)
        left_num.append(left_num[-2]+temp//2)
        temp *= 2
    range_list.append(temp)
    left_num.append(left_num[-2]+temp//2)

    def next_range(left):
        nx = bisect.bisect_right(range_list,left)
        #print(range_list[nx])
        return range_list[nx]

    def in_same_range(left,right):
        return bisect.bisect(range_list,left) == bisect.bisect(range_list,right)

    def index_to_num(left):
        index = bisect.bisect(range_list,left) - 1
        #print(index,left_num[index],left)
        return left_num[index] + 2*(left - range_list[index])

    def cal_sum(left_num,right_num):
        right_seq,left_seq = right_num//2 + (1 if right_num%2!=0 else 0),left_num//2 - \
                             (1 if right_num%2==0 else 0)
        #print(right_seq,left_seq)
        result = right_seq**2 - left_seq**2
        if left_num%2 == 0:
            result = result - left_seq + right_seq
        return result

    def cal_left_to_right(left):
        #print(range_list,left)
        add_index = bisect.bisect(range_list,left)-1
        add = range_list[add_index]
        return left_num[add_index] + 2*(add - 1)

    while left < right:
        if in_same_range(left,right):
            left_number = index_to_num(left)
            right_number = index_to_num(right)
            ans += cal_sum(left_number,right_number)%to_mod
            break
        else:
            left_number = index_to_num(left)
            right_number = cal_left_to_right(left)
            ans += cal_sum(left_number,right_number)%to_mod
            left = next_range(left)

    print(ans%to_mod)

