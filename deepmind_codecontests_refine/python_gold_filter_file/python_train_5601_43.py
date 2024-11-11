input()
l = list(map(int,input().split()))
s = sum(1/i for i in l)
print(1/s)