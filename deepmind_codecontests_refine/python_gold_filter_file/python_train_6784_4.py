import sys
a = list(map(int, input()))
b = list(map(int, input()))

for i in range(1,len(a)):
    a[i] +=a[i-1]
b_sum = sum(b)

ans = 0
ans += a[len(b)-1]%2==b_sum%2

for i in range(len(b) ,len(a)):
    ans+= (a[i]-a[i-len(b)])%2 == b_sum%2
print(ans)