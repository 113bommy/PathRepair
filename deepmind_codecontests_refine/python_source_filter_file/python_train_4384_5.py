data = list(map(int, input().split()))

w = data[0]
h = data[1]
k = data[2]

print(2*k*(w+h)-4*k*(k-1)-4*k)