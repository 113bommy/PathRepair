n, k = map(int, input().split())
a = list(map(int, input().split()))
s = input()
if n == 1:
    print(-1)
    exit(0)
have = [[] for i in range(3)]
for i in range(n):
    if s[i] == 'R':
        have[0].append(a[i])
    elif s[i] == 'O':
        have[1].append(a[i])
    else:
        have[2].append(a[i])
for i in range(3):
    have[i].sort(reverse=True)


ans1 = 0
p = 0
q = 0
was = [0, 0]
for i in range(k - 1):
    if p == len(have[0]) and q == len(have[1]):
        ans1 = -1
        break
    if p == len(have[0]):
        ans1 += have[1][q]
        q += 1
        was[1] = 1
    elif q == len(have[1]):
        ans1 += have[0][p]
        p += 1
        was[0] = 1
    elif(have[0][p] > have[1][q]):
        ans1 += have[0][p]
        p += 1
        was[0] = 1
    else:
        ans1 += have[1][q]
        q += 1
        was[1] = 1

if ans1 != -1 and sum(was) == 2:
    if p == len(have[0]) and q == len(have[1]):
        ans = -1
    elif p == len(have[0]):
        ans1 += have[1][q]
    elif q == len(have[1]):
        ans1 += have[0][p]
    else:
        ans1 += max(have[0][p], have[1][q])
if ans1 != -1 and was[0] == 0:
    if p != len(have[0]):
        ans1 += have[0][p]
    else:
        ans1 = -1
if ans1 != -1 and was[1] == 0:
    if q != len(have[1]):
        ans1 += have[1][q]
    else:
        ans1 = -1


ans2 = 0
p = 0
q = 0
was = [0, 0]
for i in range(k - 1):
    if p == len(have[2]) and q == len(have[1]):
        ans2 = -1
        break
    if p == len(have[2]):
        ans2 += have[1][q]
        q += 1
        was[1] = 1
    elif q == len(have[1]):
        ans2 += have[2][p]
        p += 1
        was[0] = 1
    elif have[2][p] > have[1][q]:
        ans2 += have[2][p]
        p += 1
        was[0] = 1
    else:
        ans2 += have[1][q]
        q += 1
        was[1] = 1

if ans2 != -1 and sum(was) == 2:
    if p == len(have[2]) and q == len(have[1]):
        ans = -1
    elif p == len(have[2]):
        ans2 += have[1][q]
    elif q == len(have[1]):
        ans2 += have[2][p]
    else:
        ans2 += max(have[2][p], have[1][q])
if ans2 != -1 and was[0] == 0:
    if p != len(have[2]):
        ans2 += have[2][p]
    else:
        ans2 = -1
if ans2 != -1 and was[1] == 0:
    if q != len(have[1]):
        ans2 += have[1][q]
    else:
        ans2 = -1

print(max(ans1, ans2))