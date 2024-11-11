def find_repost_rank(user_name):
    n = int(input())
    repost_list = []
    i = 0
    while i < n:
        r = input()
        repost_list.append([r.split()[0], r.split()[2]])
        i += 1
    return find_max(repost_list, user_name)


def find_max(repost_array, user_name, current=0, max_rank=1):

    while current < len(repost_array):
        current_rank = 1
        if repost_array[current][1].lower() == user_name.lower():
            current_rank += find_max(repost_array, repost_array[current][0], current + 1, current_rank)
        if current_rank > max_rank:
            max_rank = current_rank
        current += 1

    return max_rank


print(find_repost_rank("Polycarp"))

