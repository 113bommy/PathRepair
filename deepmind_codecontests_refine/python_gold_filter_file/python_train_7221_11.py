m = 0
for i in range(5):
    s=input().split()
    for j in range(5):
        if int(s[j])==1:
            m=abs(i-2)+abs(j-2)

print(m)