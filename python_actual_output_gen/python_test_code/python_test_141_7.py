#n = int(input())
#n, m = map(int, input().split())
n = input()
s = input()
#c = list(map(int, input().split()))
k = len(n)
n = int(n)
a = []
i = len(s) - 1
l = 0
while i - k + 1>= 0:
    if int(s[i - k + 1:i + 1]) < n:
        z = len(str(int((s[i - k + 1:i + 1]))))
        a.append(int(s[i - z + 1:i + 1]))
        i -= z
    else:
        z = len(str(int((s[i - k + 2:i + 1]))))
        a.append(int(s[i - z + 1:i + 1]))
        i -= z 
else:
    if i > - 1  and int(s[0:i + 1]) < n :
        a.append(int(s[0:i + 1]))
        i -= k
print(a)
for i in range(len(a)):
    l += a[i] * (n ** i)
print(min(l, 10**18))