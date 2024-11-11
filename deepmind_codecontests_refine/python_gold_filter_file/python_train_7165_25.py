n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = 0
for a_, b_ in zip(a, b):
    if a_ > b_:
        cnt += a_ - b_
    else:
        cnt -= (b_ - a_) // 2
if cnt <= 0:
    print('Yes')
else:
    print('No')
