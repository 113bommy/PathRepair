def find_min_cost_word(words, group_words, costs):
    cost_min = 100000000
    for word_ind in group_words:
        cost_word = costs[word_ind-1]
        cost_min = min(cost_min, cost_word)
    return cost_min

n, k, m = list(map(int, input().split()))
words = input().split()
costs = list(map(int, input().split()))
groups = []
d = {}
for i in range(k):
    tmp = list(map(int, input().split()))
    x, group_words = tmp[0], tmp[1:]
    min_cost_word = find_min_cost_word(words, group_words, costs)
    for word_ind in group_words:
        word = words[word_ind-1]
        d[word] = min_cost_word
message = input().split()
c = 0
for w in message:
    c += d[w]
print(c)