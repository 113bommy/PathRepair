n = int(input())
data = list(map(int, input().split()))
counter = {data[i]: data.count(data[i]) for i in range(n)}
cnt_better_persons = 0
answer_dict = {}
for key in reversed(list(counter.keys())):
    answer_dict[key] = 1 + cnt_better_persons
    cnt_better_persons += counter[key]
answer_list = [answer_dict[data[i]] for i in range(n)]
print(' '.join(map(str, answer_list)))