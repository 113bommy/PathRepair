n = input()
d = input()

def format_input(n,d):
    formatted_n = n.split()
    formatted_d = [int(x) for x in d.split()]
    return int(formatted_n[1]), formatted_d

def solve(n,d):
    time_limit, songs = format_input(n,d)
    devu_time = sum(songs)
    length_of_total_breaks = 10*(len(songs)-1)
    if (devu_time + length_of_total_breaks) <= time_limit:
        remaining_time = time_limit - devu_time
        number_of_jokes = remaining_time // 5
        return number_of_jokes
    else:
        return -1

print(solve(n, d))
