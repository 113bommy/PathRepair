from sys import stdin


def find_prime(max_value):
    assert max_value >= 2
    result = [2]
    for i in range(3, max_value):
        state = 1
        for item in result:
            if item * item > i:
                break
            elif i % item == 0:
                state = -1
                break
        if state == 1:
            result.append(i)
    return result


module = int(10e9) + 7

n = int(stdin.readline())
A = list(map(int, stdin.readline().split()))
number = [0 for i in range(70)]
for item in A:
    number[item - 1] += 1

prime_list = find_prime(70)

prime_map = {}
for i in range(2, 70 + 1):
    result = 0
    for item in prime_list:
        cur = i
        num = 0
        while cur % item == 0:
            num += 1
            cur = int(cur / item)
        result = result * 2 + num % 2
    prime_map[i] = result

number_dic = {0: 1}
sum_time = 0
for i in range(2, 70 + 1):
    if number[i - 1] >= 1:
        mask = prime_map[i]
        state = 1
        new_number_dic = number_dic.copy()
        for key, value in new_number_dic.items():
            new_key = key ^ mask
            if new_key in number_dic:
                number_dic[new_key] += value
            else:
                number_dic[new_key] = value
            number_dic[new_key] %= module
        sum_time += (number[i - 1] - 1)

result = number_dic[0]

for j in range(number[0] + sum_time):
    result *= 2
    result %= module
print(result-1)