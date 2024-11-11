import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")

z1, o1, o2 = map(int, input().split())
z2 = z1 + o1 - o2
f = '1' * o1 + '0' * z1
ans = 'YES'
if not z1 or o1==1 :
    if o2:
        ans = 'NO'
    else:
        s = '1' * o1 +'0'*z1
elif o2 <= z1:
    s = '1' * (o1 - 1) + '0' * o2 + '1' + '0' * (z1 - o2)
elif o2 < o1 + z1 - 1:
    s = '1' * (z1 + o1 - o2 - 1) + '0' + '1' * (o2 - z1) + '0' * (z1 - 1) + '1'
else:
    ans = 'NO'
if ans == 'NO':
    print(ans)

else:
    print(ans)
    print(f)
    print(s)
