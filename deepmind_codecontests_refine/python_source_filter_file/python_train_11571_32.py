

# 10 3
# 1 2 3 4 5 6 7 8 9 10
def get_min(n_cities, cap_tank):
    if n_cities < cap_tank:
        return n_cities - 1
    curr_lit = cap_tank - 1
    dollars = cap_tank
    i_city = 2
    while i_city <= n_cities:
        if curr_lit < (n_cities - i_city) and curr_lit < cap_tank:
            dollars += (i_city * (cap_tank - curr_lit))
            curr_lit += (cap_tank - curr_lit)
        i_city += 1
        curr_lit -= 1
    return dollars


if __name__ == '__main__':
    ls = [int(i) for i in input().split()]
    print(get_min(ls[0], ls[1]))
