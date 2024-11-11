s = input()
k = int(input())

if len(s) < k:
    print('imposssible')
else:
    print(max(0,k-len(set(s))))