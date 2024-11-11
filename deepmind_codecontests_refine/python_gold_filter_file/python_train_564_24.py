
def check_solution(_s, _t):
    is_array = False

    s_map = [0] * 26
    t_map = [0] * 26

    s_length = len(_s)
    t_length = len(_t)

    for i in range(s_length):
        s_map[ord(_s[i]) - 97] += 1

    for i in range(t_length):
        t_map[ord(_t[i]) - 97] += 1

    for i in range(26):
        if s_map[i] < t_map[i]:
            return 'need tree'

    if s_length == t_length:
        return 'array'

    s_left = 0
    t_left = 0
    while True:
        if s_left >= s_length or t_left >= t_length:
            break
        if _s[s_left] != _t[t_left]:
            s_left += 1
        else:
            s_left += 1
            t_left += 1
        if s_length - s_left < t_length - t_left:
            is_array = True
            break

    if is_array:
        return 'both'

    return 'automaton'


s = input()
t = input()

print(check_solution(s, t))
