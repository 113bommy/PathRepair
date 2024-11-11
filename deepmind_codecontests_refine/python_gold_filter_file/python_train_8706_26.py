# k k k    * - �����
# 1 2 3
# 1 * * 
# 2 2 *
# 2 4 4
# 3 3 3
# 
#
#
#
#
#
#
#
#
#
#
k = list(map(int, input().split()))
if k.count(1) >= 1 or k.count(2) >= 2 or k.count(3) >= 3 or (k.count(2) == 1 and k.count(4) == 2):
    print('YES')
else:
    print('NO')
