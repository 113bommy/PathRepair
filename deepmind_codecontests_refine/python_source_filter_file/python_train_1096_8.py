def main():
    number_of_elements = int(input())
    nicholas_lst = [int(i) for i in input().split()]

    max_idx = nicholas_lst.index(max(nicholas_lst))
    min_idx = nicholas_lst.index(min(nicholas_lst))
    len_lst = len(nicholas_lst)
    distance = abs(max_idx - min_idx)

    max_distance = 0

    if distance == (len_lst - 1):
        return len_lst - 1

    if max_idx > min_idx:
        distance_from_max_to_end = len_lst - max_idx
        distance_from_min_to_start = min_idx
        if distance_from_max_to_end > distance_from_min_to_start:
            # swap max_idx to end of lst
            return len_lst - min_idx - 1
        # swap min_idx to start of lst
        return max_idx - 1

    # start - max_idx - min_idx - end
    distance_from_min_to_end = len_lst - min_idx
    distance_from_max_to_start = max_idx
    if distance_from_min_to_end > distance_from_max_to_start:
        # swap min_idx to end of lst
        return len_lst - max_idx - 1
    # swap min_idx to start of lst
    return min_idx - 1

print(main())

