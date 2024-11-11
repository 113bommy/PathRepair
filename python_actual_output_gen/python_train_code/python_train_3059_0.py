aim, size, needed = [int(i) for i in input().split()]
mod = 10**9 + 7
used = False
table_base = {}

def num_paths(used, curr):
    if (used, curr) in table_base:
        return table_base[(used, curr)]
    count = 0
    start_used = used
    for i in range(1, size+1):
        if i == needed:
            used = True
        if curr+i < aim:
            count += num_paths(used, curr+i)
        elif curr+i == aim and used:
            count += 1
        else:
            break
    table_base[(start_used, curr)] = count
    return count

print(num_paths(used, 0))