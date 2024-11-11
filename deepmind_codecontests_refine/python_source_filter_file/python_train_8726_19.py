ai = lambda: list(map(int, input().split()))

h,w,d = ai()
ph = [0 for _ in range(h*w + 1)]
pw = [0 for _ in range(h*w + 1)]

for i in range(h):
    a = ai()
    for j in range(w):
        ph[a[j]] = i
        pw[a[j]] = j

score = [0 for _ in range(h*w + 1)]
for i in range(d+1, h*w):
    score[i] = score[i-d] + abs(ph[i]-ph[i-d]) + abs(pw[i]-pw[i-d])

q = int(input())
for _ in range(q):
    l,r = ai()
    print(score[r]-score[l])

