a = [i for i in input()]
a = len(set(a))
k = int(input())
if k > abs(a):
    print('impossible')
else:
    print(max(0, k - a))