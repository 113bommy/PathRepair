n = int(input())
h = [int(i) for i in input().split()]
dp = [0,abs(h[0]-h[1])]
for i in range(2,n): 
dp.append(min(dp[-1]+abs(h[i]-h[i-1]),dp[-2]+abs(h[i]-h[i-2])))
print(dp[-1])