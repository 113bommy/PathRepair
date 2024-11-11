N = int(input())
P = [float(a) for a in input().split()]

pre = []
post = [1]

for i in range(N):
    pre = post
    post = [0] * (i+2)
    for j in range(i+2):
        if j > 0:
            post[j] += pre[j-1] * P[i]
        if j <= i:
            post[j] += pre[j] * (1-P[i])

print(sum(post[N//2+1:]))