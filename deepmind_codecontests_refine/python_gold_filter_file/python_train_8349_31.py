t=int(input())
for i in range(t):
    h,m=[int(x) for x in input().split()]
    hr=24-h
    mr=60-m
    print(hr*60-m)