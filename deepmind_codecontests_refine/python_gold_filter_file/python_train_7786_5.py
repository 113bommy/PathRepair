S = int(input())
M = 10**9
x = (S-1)//M + 1
y = -(S - x*M)

print(0,0,1,M,x,y)