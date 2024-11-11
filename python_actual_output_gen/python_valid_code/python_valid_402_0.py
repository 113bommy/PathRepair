req_arr = [int(x) for x in input().strip()]
arr = [int(x) for x in input().strip()]
required_list = [0]*10
num_list = [0]*10
for i in req_arr:
    if i == 5:
        required_list[2] += 1
    if i == 9:
        required_list[6] += 1
    else:
        required_list[i] += 1

for i in arr:
    if i == 5:
        num_list[2] += 1
    if i == 9:
        num_list[6] += 1
    else:
        num_list[i] += 1
ans = len(req_arr)
for i, j in enumerate(required_list):
    if j > 0:
        ans = min(ans, int(num_list[i]/j))
print(ans)
