n = int(input())
a = [0] + list(map(int, input().split())) + [0]


def mnsprava(a):
    inf = int(2e9) + 1
    ans1 = [0] * (n + 2)
    st = [0]
    for i in range(1, n + 2):
        while a[st[-1]] > a[i]:
            ans1[st.pop()] = n - i + 1
        st.append(i)
    ans1.reverse()
    return ans1[1:-1]


alf = mnsprava(a)
a.reverse()
right = [0] * (n + 2)
for i in range(1, n + 1):
    if a[i] >= a[i - 1]:
        right[i] = a[i] + right[i - 1]
    else:
        right[i] = right[alf[i - 1]] + a[i] * (i - alf[i - 1])
bet = mnsprava(a)
a.reverse()
left = [0] * (n + 2)
for i in range(1, n + 1):
    if a[i] >= a[i - 1]:
        left[i] = a[i] + left[i - 1]
    else:
        left[i] = left[bet[i - 1]] + a[i] * (i - bet[i - 1])
right.reverse()

imax = 0
mx = 0
for t in range(1, n+1):
    if left[t] + right[t] - a[t] > mx:
        mx = left[t] + right[t] - a[t]
        imax = t
ans = [0] * (n + 2)
ans[imax] = a[imax]

for i in range(imax - 1, 0, -1):
    if a[i] < a[i+1]:
        ans[i] = a[i]
    else:
        ans[i] = ans[i+1]

for i in range(imax + 1, n + 1):
    if a[i] < a[i-1]:
        ans[i] = a[i]
    else:
        ans[i] = ans[i-1]

for i in range(1, n+1):
    print(ans[i], end=" ")


