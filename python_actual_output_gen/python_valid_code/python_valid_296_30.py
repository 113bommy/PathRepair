n, time = [int(i) for i in input().split()]
days = [int(i) for i in input().split()]
for i in range(n):
    time-=86400 - days[i]
    if(time == 0):
        print(i+1)
        break
