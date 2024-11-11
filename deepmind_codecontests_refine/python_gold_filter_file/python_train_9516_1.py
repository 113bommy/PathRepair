def colour_the_fence():
    n = int(input())
    litre_list = list(map(int, str(input()).split()))
    paint_dict = {}

    for i in range(1, 10):
        if litre_list[i-1] > n:
            continue
        paint_dict[litre_list[i-1]] = i
    # print(paint_dict)

    min_litre = min(litre_list)
    # print("min litre ", min_litre)

    if min_litre > n:
        print(-1)
    else:
        x = divmod(n, min_litre)
        # x[0] is quotient and x[1] is remainder
        remaining_litres = x[1]
        largest_num = (x[0]*str(paint_dict[min_litre]))
        # print("Rem ", remaining_litres)

        if remaining_litres != 0:
            while remaining_litres > 0:
                replace = find_max(paint_dict, remaining_litres + min_litre)
                # print("replace ", replace)
                # this can possibly occupy the last digit
                # -1 will not be returned (line 31)
                if paint_dict[replace] < paint_dict[min_litre] or replace == min_litre:
                    break
                else:
                    largest_num = (((largest_num))[1:])
                    # removing the first digit
                    remaining_litres += min_litre
                    remaining_litres -= replace
                    largest_num = ((largest_num) + str(paint_dict[replace]))
                    # print("Largest num ", largest_num)
                    # print("Rem ", remaining_litres)

        print((''.join(sorted((largest_num), reverse=True))))


def find_max(given_dict, limit):
    # to find the greatest key value <= limit
    # max_value = -1
    # for i in range(len(given_list)):
    #     if given_list[i] <= limit:
    #         if given_list[i] > max_value:
    #             max_value = given_list[i]
    # return max_value
    max_value = max_key = -1
    for key in given_dict.keys():
        if key <= limit:
            if given_dict[key] > max_value:
                max_value = given_dict[key]
                max_key = key
    return max_key


if __name__ == '__main__':
    colour_the_fence()
