# Serval and Paranthesis
from collections import Counter

n = int(input())

data = list(input())

def checkData(data):
    counts = Counter(data)
    toClose = 0
    btoClose = len(data)/2 - counts[')']
    for i in range(len(data)-1,-1,-1):
        if data[i] is '?':
            if btoClose:
                data[i] = ')'
                btoClose -= 1
            else:
                data[i] = '('

    for index, value in enumerate(data):
        if value is '(':
            toClose += 1
        elif value is ')':
            toClose -= 1
            if not toClose:
                if index != len(data) - 1:
                    return ':('
    if toClose:
        return ':('
    else:
        return ''.join(data)


print(checkData(data))
