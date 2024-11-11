n = int(input())
s = list(map(int,input().split()))
min1=0
max1=s[0]
c=1
for i in range(1,len(s)):
    if s[i] > max1:
        c+=1
        max1=s[i]
    elif s[i] < min1:
        c+=1
        min1=s[i]
print(c)
