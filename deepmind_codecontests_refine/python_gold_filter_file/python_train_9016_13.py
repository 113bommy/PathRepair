# python3
# utf-8

n, k, m = (int(x) for x in input().split())
numbers = [int(x) for x in input().split()]
mod___numbers = [[] for x in range(m)]
for number in numbers:
    mod___numbers[number % m].append(number)
for curr_ans in mod___numbers:
    if len(curr_ans) >= k:
        print('Yes')
        print(*curr_ans[:k])
        exit()
print('No')
