n=int(input())
a=sorted(list(map(int,input().split())))
if a[-1]<=25:
    print(0)
else:
    print(abs(a[0]-25))