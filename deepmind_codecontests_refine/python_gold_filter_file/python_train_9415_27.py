n, d = map(int, input().split())
l = map(int, input().split())
s = sum(l)
gap = (n-1)*10
req_time = gap + s
if req_time <= d:
    print((d-s)//5)
else:
    print(-1)