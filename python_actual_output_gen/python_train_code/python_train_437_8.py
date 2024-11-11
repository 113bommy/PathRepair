N, H = list(map(int,input().split()))
a = 0
b = [0]
for i in range(N):
    A = list(map(int,input().split()))
    a = max(a,A[0])
    b += [A[1]]
b = sorted(b)[::-1]
for i in range(N):
    if(H<=0):
        break
    if (b[i] > a):
        H -= b[i]
    else:
        i += int(H/a)+(0!=H%a)
        break
print(i)

