h,w,a,b = map(int,input().split())
ans = [["0"]*a+["1"]*(w-a) for _ in range(b)]+[["1"]*a+["0"]*(w-a) for _ in range(h-b)]
for i in range(h):print(" ".join(ans[i]))