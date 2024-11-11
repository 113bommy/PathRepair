# import os


s, v1, v2, t1, t2 = map(int, input().split())

p1 = (2*t1) + (s * v1)
p2 = (2*t2) + (s * v2)

if p1 < p2:
    print('First')
elif p1 > p2:
    print('Second')
else:
    print('Frienship')




# 04/01 - 21
# 05/01 - 27
# 06/01 - 28


# t = int(input())

# for _ in range(t):
#     n = int(input())

#     a = list(map(int, input().split()))

    