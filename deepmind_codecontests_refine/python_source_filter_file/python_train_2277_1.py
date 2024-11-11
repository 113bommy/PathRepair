import re
try:
    ls = num = []
    result = 0
    while True:
        ls.append(input())
except:
    for i in ls:
        for s in range(re.findall(r'\d+', i)):
            result += int(s)
    print(result)