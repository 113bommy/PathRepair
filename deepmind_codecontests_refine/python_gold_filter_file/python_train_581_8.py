import pdb

if __name__ == "__main__":
    digits = [int(i) for i in input()]

    def three_digits_sum(digits):
        first_three = 0
        last_three = 0
        for i in range(3):
            first_three += digits[i]
            last_three += digits[i+3]
        return [first_three, last_three]

    def calculate(digits):
        og_sum = three_digits_sum(digits)
        diff = abs(og_sum[0] - og_sum[1])
        if diff == 0:
            return 0
        else:
            if og_sum[0] < og_sum[1]:
                lower = list(digits[0:3])
                upper = list(digits[3:6])
            else:
                lower = list(digits[3:6])
                upper = list(digits[0:3])
            biggest_diff_amt = 0
            biggest_diff_idx = 0
            biggest_diff_set = None
            biggest_diff_list = None
            for i in range(3):
                el_diff = 9 - lower[i]
                if el_diff >= diff:
                    return 1
                elif el_diff > biggest_diff_amt:
                    biggest_diff_list = lower
                    biggest_diff_idx = i
                    biggest_diff_set = 9
                    biggest_diff_amt = el_diff
            for i in range(3):
                el_diff = upper[i]
                if el_diff >= diff:
                    return 1
                elif el_diff > biggest_diff_amt:
                    biggest_diff_list = upper
                    biggest_diff_idx = i
                    biggest_diff_set = 0
                    biggest_diff_amt = el_diff
            biggest_diff_list[biggest_diff_idx] = biggest_diff_set
            return 1 + calculate(lower + upper)

    print(calculate(digits))