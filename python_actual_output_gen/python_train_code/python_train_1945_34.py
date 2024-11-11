input()
l = list(map(int,input().split()))
s = sum(1/i for i in l)
print(round(1/s,3))