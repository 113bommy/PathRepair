
def input_int():
    return(int(input()))

def input_int_list():
    return(list(map(int,input().split())))

def input_input_map():
    return(map(int,input().split()))

def run():
    q_num = input_int()

    for i in range(q_num):

        num_count, first_num, second_num = input_input_map()

        diff_num = second_num - first_num

        one_step_num = diff_num

        for num in range(1, diff_num // 2 + 1):
            if diff_num % num == 0 and diff_num / num < num_count:
                one_step_num = num
                break

        # startが分かればいい。

        total_diff = one_step_num * (num_count - 1)

        if second_num - total_diff < 1:

            diff_count = second_num // one_step_num

            if second_num - one_step_num * diff_count == 0:
                start = second_num - one_step_num * (diff_count - 1)
            else:
                start = second_num - one_step_num * diff_count
        else:
            start = second_num - total_diff

        results = []
        for j in range(num_count):
            results.append(start + one_step_num * j)

        print(" ".join(map(str, results)))
        # print("aaa")



run()

# 217871987498122 10
#   2128012501878 10

# 100000000000000001
# 899999999999999999


