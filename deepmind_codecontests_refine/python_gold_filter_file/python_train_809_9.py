n = int(input())
a = list(map(int, input().split()))
s = 1
for i in a:
    s ^= i
if s == 1:
    print('Yes')
else:
    print('No')