a = [i for i in input()]
s = len(set(a))
k = int(input())
if k > len(a):
    print('impossible')
else:
    print(max(0, k - s))