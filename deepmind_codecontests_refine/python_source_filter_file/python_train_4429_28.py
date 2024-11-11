l = list(input().split())
n = int(l[0])
c = int(l[1])
points = list(input().split())
points = [int(i) for i in points]
time = list(input().split())
time = [int(i) for i in time]
sumtime = 0
limak = 0
redwoosh = 0
for i in range(n):
    sumtime += time[i]
    limak += max(0, (points[i] - (c * sumtime)))
sumtime = 0
for i in range(n-1, 0, -1):
    sumtime += time[i]
    redwoosh += max((points[i] - (c * sumtime)), 0)
if limak > redwoosh:
    print("Limak")
elif limak < redwoosh:
    print("Redwoosh")
else:
    print("Tie")