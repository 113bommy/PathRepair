L = int(input())
r = 0
answer = []

while 2**r <= L:
    r += 1
N = r

for i in range(r-1):
    answer.append([i,i+1,0])
    answer.append([i,i+1,2**i])


for t in range(N-1,0,-1):
    if L - 2**(t-1) >= 2**(r-1):
        answer.append([t,N,L-2**(t-1)])
        L -= 2**(t-1)

answer.insert(0,[N,len(answer)])

for ans in answer:
    print(*ans)