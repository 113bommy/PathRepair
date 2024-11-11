flag="NO"
for _ in range(int(input())):
    l=input().split()
    if int(l[1])>=2400 and int(l[2])>2400:
        flag="YES"
print(flag)