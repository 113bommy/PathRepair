import math
t = int(input())
for i in range(t):
    a,b,c,d = list(map(int,input().split()))
    if a<b:
        print(b)
    elif (c-d)<=0:
        print(-1)
    else:
        reset_count = math.ceil((a-b)/(c-d))
        total_time = b+(reset_count*c)
        print(total_time)
