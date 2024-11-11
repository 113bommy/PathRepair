h,w = map(int,input().split())
ans = float("Inf")
if h % 3 == 0 or w % 3 == 0:
    print(0)
    exit()
for i in range(1,h):
    a = (h-i)*(w//2)
    b = (h-i)*-(-w//2)
    ans = min(ans,abs(max(i*w,a,b)-min(i*w,a,b)))
for i in range(1,w):
    a = (w-i)*(h//2)
    b = (w-i)*-(-h//2)
    ans = min(ans,abs(max(i*h,a,b)-min(i*h,a,b)))
print(min(ans,h,w))