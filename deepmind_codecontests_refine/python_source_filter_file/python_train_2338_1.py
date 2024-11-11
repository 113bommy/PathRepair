#O(n^2) solution (double pointer)
n =int(input())
list_ = list(map(int,input().split()))

tot_sum = sum(list_)

if len(list_) < 3 or (tot_sum %3 != 0):
    print(0)
else:
    '''
    #O(n^2) with O(n^2) memory

    d = [[['None'] for i in range(1,n-1)] for j in range(1,n-1)]

    tot_sum = sum(list_)
    sum_ = 0
    #initialize
    d[-1][0] = [list_[0], tot_sum - list_[0] - list_[-1], list_[-1]]

    for i in range(1,n-1):
        if i > 1:
            prev_ = d[-i+1][0]
            d[-i][0] =  [prev_[0], prev_[1] - list_[-i], prev_[2] + list_[-i]]
            if d[-i][0][0] == d[-i][0][1] and d[-i][0][1] == d[-i][0][2]:
                sum_+=1

        for j in range(1,n-i-1):
            prev_d  = d[-i][j-1]
            d[-i][j] = [prev_d[0] + list_[j],prev_d[1] - list_[j], prev_d[2]]
            if d[-i][j][0] == d[-i][j][1] and d[-i][j][1] == d[-i][j][2]:
                sum_+=1




    print(sum_)
    '''

    #d = [[['None'] for i in range(1,n-1)] for j in range(1,n-1)]

    '''
    #O(n^2) solution with O(1) space
    sum_ = 0
    #initialize
    #d[-1][0] = [list_[0], tot_sum - list_[0] - list_[-1], list_[-1]]
    prev_ = [list_[0], tot_sum - list_[0] - list_[-1], list_[-1]]
    if prev_[0] == prev_[1] and prev_[1] == prev_[2]:
        sum_+=1


    for i in range(1,n-1):
        temp_1 = prev_
        if i > 1:
            prev_ = temp_1
            prev_ =  [prev_[0], prev_[1] - list_[-i], prev_[2] + list_[-i]]
            if prev_[0] == prev_[1] and prev_[1] == prev_[2]:
                sum_+=1
        if prev_[2] > tot_sum/3 +1 or prev_[1] < tot_sum/3:
            break
        temp_2 = prev_
        for j in range(1,n-i-1):
            prev_d  = temp_2
            prev_d = [prev_d[0] + list_[j],prev_d[1] - list_[j], prev_d[2]]
            if prev_d[0] == prev_d[1] and prev_d[1] == prev_d[2]:
                sum_+=1
            temp_2  = prev_d
            if prev_d[0] > tot_sum/3 +1 or prev_d[1] < tot_sum/3:
                break


    print(sum_)
    '''
    sum_first = [0 for i in range(n-2)]
    sum_second = [0 for i in range(n-2)]

    sum_first[0], sum_second[0] = list_[0], list_[-1]
    for i in range(1,n-2):
        sum_first[i] = sum_first[i-1] + list_[i]
        sum_second[-i-1] = sum_second[-i] + list_[-i-1]

    for i in range(n-2):
        if sum_first[i] == tot_sum /3 :
            sum_first[i] =1
        else:
            sum_first[i] = 0
        if sum_second[-i-1] == tot_sum /3 :
            sum_second[-i-1] = 1
        else:
            sum_second[-i-1] = 0


    final_second = sum_second.copy()
    for i in range(1,n-2):
        final_second[-i-1] = final_second[-i] + sum_second[-i-1]

    sum_ = 0
    for i in range(n-2):
        sum_ += sum_first[i]*final_second[-n+i+2]

    print(sum_)
