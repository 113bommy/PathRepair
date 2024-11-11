steps=0
n=int(input())
ip=list(input())
pwd=list(input())
for i in range(0,n):
    diff=(abs(int(ip[i])-int(pwd[i])))
    if diff>5:
        diff=10-diff
    steps+=diff
print(steps)