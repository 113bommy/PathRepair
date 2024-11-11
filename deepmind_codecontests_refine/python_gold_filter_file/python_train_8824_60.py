N = int(input())

s=0
for i in range(1,N+1):
    n = int(N/i)
    s += n*(i+i*n)/2
print(int(s))