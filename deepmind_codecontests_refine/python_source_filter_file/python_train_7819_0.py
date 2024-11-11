n = int(input())
a = []
lms = []
max = 0
for i in range(n):
    b = []
    lms.insert(i,0)

    value = input()
    t = 0
    for c in map(int, value.split(" ")):
        b.insert(t, c)
        t += 1

    k = b[0]

    for j in range(1,k):
        p = b[j]
        if p > max:
            max = p
        if p > lms[i]:
            lms[i] = p
    a.insert(i,b)
ans = 0
for i in range(n):
    ans+=(max-lms[i])*(len(a[i])-1)
print(ans)