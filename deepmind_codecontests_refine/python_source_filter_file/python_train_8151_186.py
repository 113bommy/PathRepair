line = input().split()

n, k, l, c, d, p, nl, np = int(line[0]), int(line[1]), int(line[2]), int(line[3]), int(line[4]), int(line[5]), int(line[6]), int(line[7])

total_drinks = k*l
lemon_slices = c*d
# print(total_drinks, lemon_slices)


print(min((total_drinks//n), lemon_slices, (p//np)) // n)