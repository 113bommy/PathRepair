if __name__ == '__main__':
    n = int(input())
    in_ = list(map(int, input().split()))
    out_ = list(map(int, input().split()))
    in_pointer = 0
    out_pointer = 0
    over_takers = {}
    while out_pointer < n:
        if in_[in_pointer] in over_takers:
            in_pointer += 1
        if in_[in_pointer] == out_[out_pointer]:
            in_pointer += 1
            out_pointer += 1
        else:
            over_takers[out_[out_pointer]] = 0
            out_pointer += 1
    print(len(over_takers))
