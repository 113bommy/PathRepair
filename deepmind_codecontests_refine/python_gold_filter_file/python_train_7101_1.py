from heapq import *
string = input()
k = int(input())
m = k
t = len(string)
u = t * (t + 1) / 2
if k > u:
    print('No such line.')
    exit()
substring = [[string[i],i] for i in range(t)]
heapify(substring)
while m > 0:
    m -= 1
    a = heappop(substring)
    if a[1] < t - 1:
        b = a[0] + string[a[1]+1]
        heappush(substring,[b, a[1] + 1])
print(a[0])
