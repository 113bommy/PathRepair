s = input()
constant = 10**9 + 7
def possible_ways(s):
    last_a_count = 1
    count = 0
    has_a = has_b = False
    for c in s:
        if c == 'a':
            has_a = True
            if has_b:
                last_a_count = count + 1
            count += last_a_count
            last_a_count %= constant
            count %= constant
            has_b = False
        elif c == 'b' and has_a:
            has_b = True
    return count

print(possible_ways(s))