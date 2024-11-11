n = int(input())
a = [int(i) for i in input().split()]
if a.count(0)>0:
    print('HARD')
else:
    print('YES')