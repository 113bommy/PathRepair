import math
n, v_bus, v_student = map(int, input().split())
stops = list(map(int, input().split()))
uni = list(map(int, input().split()))

ans = []
for i in range(1, len(stops)):
    x = (stops[i] / v_bus + math.hypot(uni[0] - stops[i], uni[1])) / v_student
    y = math.hypot(uni[0] - stops[i], uni[1])
    z = i + 1
    ii = (x, y, z)
    ans.append(ii)
# find the tuple w/ min value; i+1 is irrelevans as smallest i+1 can be > smallest distance
print(min(ans)[2])

