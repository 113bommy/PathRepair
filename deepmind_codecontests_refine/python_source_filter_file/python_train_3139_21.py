import math
arr = input()
H, M = [int(x) for x in arr.split(' ')]
 
arr = input()
arr = [int(x) for x in arr.split(' ')]

p_sum = [0]*M

s = 0

for i in range(M):
    s += arr[i]
    p_sum[i] = s
    if abs(s)>=H and s<=0:
        print(i+1)
        quit()
    
#print(p_sum)

# A = round deduction
# m = max deduction during round
if p_sum[-1]>=0:
    print(-1)
    quit()
    
rounds = (H-abs(min(p_sum)))/abs(p_sum[-1])
print(rounds)
N = math.ceil( rounds )
#print(N)

H = H + p_sum[-1]*N
print(H)
res = N*M

s = 0
for i in range(M):
    s += arr[i]
    #p_sum[i] = s
    if abs(s)>=H and s<=0:
        print(res+i+1)
        quit()