tests =int(input())
for i in range(tests):
    h,m = map(int,input().split())
    minutes  = (24-h)*60 +(60-m)
    print(minutes)