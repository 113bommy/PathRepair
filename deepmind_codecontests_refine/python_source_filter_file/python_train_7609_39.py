#1041A
n = int(input())
a = list(map(float,input().split()))
mn = min(a)
mx = max(a)
print(mx-mn +1-n)