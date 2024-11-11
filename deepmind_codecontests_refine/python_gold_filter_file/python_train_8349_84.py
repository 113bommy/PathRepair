t=int(input())
for i in range(t):
    h,m=[int(x) for x in input().split()]
    h1=24-h
    m1=60-m
    print(h1*60+m1-60)