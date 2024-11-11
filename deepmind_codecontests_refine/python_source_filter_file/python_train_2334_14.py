from collections import Counter
k=int(input())
b=Counter()
for i in range(4):
    for i in input().rstrip():
        if 48<=ord(i)<=57:
            b[int(i)]+=1
ans="YES"
for i in b:
    if b[i]>k:
        ans="NO"
        break
print(ans)