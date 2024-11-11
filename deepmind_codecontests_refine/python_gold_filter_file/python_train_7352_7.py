n = int(input())
l = list(map(int, input().split()))

kill_pos_min = []
for i in range(n):
    kill_pos_min.append(i-l[i])

cnt=1
min_pos = 999999999999
for i in range(n-1,-1,-1):
    if (kill_pos_min[i]<min_pos):
        min_pos = kill_pos_min[i]
    else:   
        kill_pos_min[i] = min_pos

for i in range(n-1):
    if (i<kill_pos_min[i+1]):
        cnt+=1      
#print(kill_pos_min)
print(cnt)