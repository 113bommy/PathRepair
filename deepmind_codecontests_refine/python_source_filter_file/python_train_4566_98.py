w,a,b = map(int,input().split())
ma = max(a,b)
mi = min(a,b)
print(max(max-(mi+w),0))