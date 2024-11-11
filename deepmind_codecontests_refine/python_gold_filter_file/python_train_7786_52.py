S = int(input())
N = 10**9
x = (N - S%N) % N
y = -(-S//N)
print(0,0,10**9,1,x,y)
