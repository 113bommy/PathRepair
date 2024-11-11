import sys

information = [int(x) for x in sys.stdin.readline().strip().split()]
ans = information[0]
for i in range(information[1]):
    if ans % 10 == 0:
        ans = ans/10
    else:
        ans = ans-1

print(ans)