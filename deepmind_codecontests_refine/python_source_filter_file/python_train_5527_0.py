n, m = map(int, input().split())

a = list(map(int, input().split()))

if n==1:
    print(max(a[0],m-a[0]-1,m-1))
    exit()

s1 = [0]*(n+1)
s2 = [0]*(n+1)
s1[0] = a[0]
a.append(m)
n+=1

for i in range(1,n):
    if i%2==0:
        s1[i] = s1[i-1] + a[i]-a[i-1]
        s2[i] = s2[i-1]
    else:
        s2[i] = s2[i - 1] + a[i] - a[i - 1]
        s1[i] = s1[i - 1]

sum1 = s1[n-1]
sum2 = s2[n-1]

ans = sum1

for i in range(n-1):
    if i%2==0:
        ans = max(ans, s1[i]-1+sum2-s2[i])
    else:
        ans = max(ans, s1[i]+1+sum2-s2[i])

print(ans)