n = int(input())
l = [int(x) for x in input().split()]
l = list(set(l))
flag = 0
l.sort()
for i in range(len(l)-1):
    if l[i+1] < 2*l[i]:
        flag = 1
        print('YES')
        break
if not flag:
    print('NO')