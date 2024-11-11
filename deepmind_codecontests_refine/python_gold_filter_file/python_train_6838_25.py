q = input()
n, k = q.split()
n = int(n)
k = int(k)
s2 = []
s1 = [0]
p = 0
s = input().split()
for i in range(n):
    if s[i] in s1:
        p+=1
    else:
        s1.append(s[i])
        s2.append(i+1)
if k <= len(s2):
    print("YES")
    for i in range(k):
        print(s2[i], end = " ")
else:
    print("NO")
