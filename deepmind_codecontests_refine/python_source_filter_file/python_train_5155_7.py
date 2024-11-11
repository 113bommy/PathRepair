def find_right(x, data):
    answer = -1
    for i in range(len(data)):
        if data[i] == x:
            answer = i
    return answer

def find_left(x, data):
    for i in range(len(data)):
        if data[i] == x:
            return i


n = int(input())
data = list(map(int, input().split()))
min1 = min(data)
index_min_r = find_right(min1, data)
index_min_l = find_left(min1, data)
k = data.count(min1)
c = index_min_r - index_min_l - 1
help = []
for i in range(n):
    if data[i] == min1:
        help.append(i)
answer = []
for i in range(1, len(help)):
    answer.append(help[i] - help[i] - 1)
answer.append(n - (help[-1] - help[0]) - 1)
print(max(answer) + n * min1)