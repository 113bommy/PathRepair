import sys

n = sys.stdin.readline()
while n:
    if '0' not in n:
        print(n[:-1])
    else:
        for i in range(len(n)):
            if n[i] == '0':
                break
        res = "{}{}".format(n[:i], n[i + 1:])
        for j in range(len(res)):
            if res[j] != '0':
                break
        if len(res[j:-1]) == 0:
            print(0)
        else:
            print(res[j:-1])
    n = sys.stdin.readline()
