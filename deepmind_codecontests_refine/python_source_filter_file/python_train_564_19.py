s = input()
t = input()

res = ""
temp = ""
arr_t =[]

for i in s:
    if i not in arr_t:
        arr_t.append(i)
arr_s_cnt = len(arr_t) * [0]
arr_t_cnt = len(arr_t) * [0]
for i in range(len(arr_t)):
    for j in s:
        if j == arr_t[i]:
            arr_s_cnt[i] += 1
    for j in t:
        if j == arr_t[i]:
            arr_t_cnt[i] += 1

for i in range(len(arr_s_cnt)):
    if arr_s_cnt[i] < arr_t_cnt[i]:
        res = "need tree"
        break

if res == "":
    if len(s) == len(t):
        res = "array"
    elif len(s) > len(t):
        if t in s:
            res = "automaton"
        else:
            x = 0
            for i in range(len(t)):
                for j in range(x, len(s)):
                    if t[i] == s[j]:
                        temp += s[j]
                        x = j + 1
                        break
            if temp == t:
                res = "automaton"
            else:
                res = "both"

print(res)
