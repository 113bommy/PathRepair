import math

t = int(input())
for i in range(t):
    s = input()
    min_length = len(s) + 1
    dic = {}
    dic["1"] = -1
    dic["2"] = -1
    dic["3"] = -1
    for a, b in enumerate(s):
        dic[a] = b
        if dic["1"] != -1 and dic["2"] != -1 and dic["3"] != -1:
            min_length = min(min_length, max(dic["1"], dic["2"], dic["3"]) - min(dic["1"], dic["2"], dic["3"]) + 1)
    if min_length == len(s) + 1:
        print(0)
    else:
        print(min_length)
