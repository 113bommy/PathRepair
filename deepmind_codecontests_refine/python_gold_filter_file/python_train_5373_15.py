s = input()
k = int(input())
if len(s) < k:
    print('impossible')
    exit(0)
print(max(0, k - len(set(list(s)))))