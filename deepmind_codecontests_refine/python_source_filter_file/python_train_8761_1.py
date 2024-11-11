n, k = map(int, input().strip().split())

t = input().strip()

l1 = t.rfind('1') - t.find('1') + 1
l2 = t.rfind('0') - t.find('0') + 1

if l1 <= k or l2 <= k:
    print('tokitsukaze')
elif k < n // 2 or l1 > k + 2 or l2 > k + 2:
    print('once again')
else:
    print('quailty')
