t=int(input())
for i in range(t):
    hh,mm=map(int, input().split())
    print(60*24 - 60*hh - mm)
    