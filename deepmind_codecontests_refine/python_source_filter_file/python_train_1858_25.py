import collections
h,w = map(int, input().split())
s = ''.join([''.join(input().split()) for _ in range(h)])

ctr = collections.Counter(s)
if h % 2 == 0 and w % 2 == 0:
    four, two = h*w//4, 0
elif h % 2 == 0:
    four, two = (h*w-h)//4, h//2
elif w % 2 == 0:
    four, two = (h*w-w)//4, w//2
else:
    four, two = (h*w-h-w+1), (h+w-1)//2

cf = sum([c//4 for c in ctr.values()])
ct = sum([(c%4)//2 for c in ctr.values()])

if cf >= four and ct + 2*(cf-four) >= two:
    print('Yes')
else:
    print('No')