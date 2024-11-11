n = int(input())
for i in range(n):
    a = int(input())
    s = [int(i) for i in input().split(' ')]
    minimum = min(s)
    tmp = 0
    for j in s:
        if minimum-j%2==1:
           tmp=1
           break
    if tmp==1:
        print("NO")
    else:
        print("YES") 