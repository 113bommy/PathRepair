n = int(input())
x_list = list(map(int, input().split(' ')))

p = int(sum(x_list)/n)

print(sum([(x - p)**2 for x in x_list]))
