s, v1, v2, t1, t2 = map(int, input().split())
tf = t1 * 2 + s / v1
ts = t2 * 2 + s / v2
if tf < ts:
    print('First')
if tf > ts:
    print('Second')
if tf == ts:
    print('Friendship')