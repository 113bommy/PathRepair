tests =int(input())
for i in range(tests):
    h,m = map(int,input().split())
    minutes  = (24*60) - (h*60+m)
    print(minutes)