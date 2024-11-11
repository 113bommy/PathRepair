t=int(input())
for i in range(t):
    h,m=map(int,input().split())
    print(((24-h-1)%24)*60+(60-m)%60)
