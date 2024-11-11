n = input()

lst = list(map(int, list(n)))
print(sum(lst[0], lst[0] - 1 + 9 * (len(lst) - 1)))
