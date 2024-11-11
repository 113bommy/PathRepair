n = int(input())
a = list(map(int, input().split(" ")))
b = []
s1 = 0
s2 = 0
i = 0
j = n-1
flag=1
s1 = s1+a[i]
s2 = s2+a[j]
while i<=j:
    #print(s1,s2)
    if s1 < s2:
        i=i+1
        s1=s1+a[i]
    if s1 > s2:
        j = j-1
        s2=s2+a[j]
    if s1 == s2:
        flag = 0
        b.append(s1)

        i += 1
        j = j-1
        s1 += a[i]
        s2 += a[j]
if flag == 1:
    print(0)
else:
    print(max(b))

