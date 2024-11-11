a,b = input().split()
a = int(a)
b = int(b)
s = input()
d = list(input().strip().split())

j = 0
for i in range(0,len(s)):
    if(s[i] in d):
        j = i
        # print(j)
        break

ans = 0
finalans = 0
for i in range(j,len(s)):
    if(s[i] not in d):
        finalans += (ans)*(ans + 1)//2
        # finalans = finalans//2
        # print(finalans)
        ans = 0
    else:
        ans += 1

if(ans > 0):
    finalans += (ans)*(ans + 1)//2
        
print(finalans)