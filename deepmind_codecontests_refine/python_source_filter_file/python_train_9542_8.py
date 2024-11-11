n, k, m = map(int, input().split())
language_array = input().split()
cost_array = list(map(int, input().split()))

language_dic = {}
for i in range(0, n):
    language_dic[language_array[i]] = i+1

# print(language_dic)

def get_min(ids, costs):
    tmp_min = 1e9
    for tmp_id in ids:
        tmp_min = min(tmp_min, costs[tmp_id-1])
    return tmp_min

cost_dic = {}
for i in range(0, k):
    group = list(map(int, input().split()))
    x = group[0]
    del group[:1]
    tmp_min = get_min(group, cost_array)
    for j in range(0, x):
        cost_dic[group[j]] = tmp_min

# print(cost_dic)

ans = 0
for tmp_str in input().split():
    # print("tmp_str==" + tmp_str + ", id==" + str(language_dic[tmp_str]))
    tmp_id = language_dic[tmp_str]
    ans += cost_dic[tmp_id]

print(ans)






    


