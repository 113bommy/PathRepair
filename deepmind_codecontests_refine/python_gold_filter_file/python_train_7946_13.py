n , t1 , t2 , k = map(int , input().split())

speeds = []

for i in range(n):
    u , v = map(int , input().split())
    speeds.append([u , v])

tally = []

for i in range(n):
    if t1*((100 -k)/100) > t2:
        tally.append([i + 1 , (t1*((100-k)/100)*max(speeds[i][0] , speeds[i][1])) + t2*(min(speeds[i][0] , speeds[i][1]))])
    else:
        tally.append([i + 1  , t1*((100-k)/100)*min(speeds[i][0] , speeds[i][1]) + t2*(max(speeds[i][0] , speeds[i][1]))])

# print(tally)
tally.sort(reverse=True , key = lambda x : x[1])
for i in range(n):
    print(tally[i][0] , "{:.2f}".format(tally[i][1]))