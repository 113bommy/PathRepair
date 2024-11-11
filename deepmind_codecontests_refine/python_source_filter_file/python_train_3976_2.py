num_cases = int(input())

for case in range(num_cases):
    str_, int_, exp_ = [int(x) for x in input().split(' ')]

    if exp_ == 0:
        if str_ <= int_:
            print(0)
        else:
            print(1)
        continue
    comp = (int_ + exp_ - str_) / 2 + 1
    if comp <= 0:
        print(exp_+1)
    else:
        print(exp_ - int(comp) + 1)