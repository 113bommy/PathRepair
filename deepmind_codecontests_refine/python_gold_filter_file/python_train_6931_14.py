
N = int(1e5 + 2)

prime = []
is_prime = N * [1]
color = N * [2]
for i in range(N):
    if i < 2: continue
    
    if is_prime[i]:
        j = 2 * i
        while(j < N):
            is_prime[j] = 0
            j += i

        prime.append(i)
        color[i] = 1
'''
cnt = 2
for num in prime:
    j = 2 * num
    while(j < N):
        color[j] = cnt if color[j] == 0 else color[j]
        j += num

    #cnt += 1
'''

n = int(input())
print(max(color[2:n + 2]), ' '.join(map(str, color[2:n + 2])), sep = '\n')

