n, k = map(int, input().split())
time_rem = 240 - k

count = 0
while(time_rem - (5*(count+1))> 0):
    count += 1
    time_rem -= 5*count

print(min(n,count))
