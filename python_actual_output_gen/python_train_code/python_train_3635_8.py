a = list(map(int,input().split()))
k2 = a[0]
k3 = a[1]
k5 = a[2]
k6 = a[3]
s = 0
s += min(k2,k5,k6)*256
s += min((k2 - min(k2,k3,k6)),k3)*32
print(s)