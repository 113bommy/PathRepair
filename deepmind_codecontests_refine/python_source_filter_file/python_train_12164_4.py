n = int(input())
t = [int(x) for x in input().split()]
v = [int(x) for x in input().split()]
tTotal = sum(t)*2
speed = [min(i/2,(tTotal-i)/2) for i in range(tTotal+1)]
#?

start=0
end=0
#iter through segments
for i in range(n):
    end += t[i]*2
    for j in range(tTotal+1):
        speed[j] = min(speed[j], v[i] + max(0, -(j-start)/2, (j-end)/2))
    start = end

print(sum(speed)/2)