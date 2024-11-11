s = input()
n = int(input())
dictionary = set(s)
if len(s) >= n:
    n -= len(dictionary)
    print(max(0, n))
else:
    print('impossible')
