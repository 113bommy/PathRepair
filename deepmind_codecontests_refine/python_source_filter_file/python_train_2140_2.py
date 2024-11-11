#ROUNIAAUDI
n, m = map(int, input().split())

c = list(map(int, input().split()))

t = list(map(int, input().split()))

r = 0

j = 0

for ct in c:
    print(ct)

    while j + 1 < m and abs(ct - t[j]) >= abs(ct - t[j + 1]):
       # print(j,end=" ")
        j += 1

    r = max(r, abs(ct - t[j]))

print(r)

