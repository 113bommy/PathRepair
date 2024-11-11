[n, w]=list(map(int, input().split()))
arr=list(map(int, input().strip().split()))
lw_lim, up_lim = 0, w
for idx in range(n):
    lw_lim=max(0, lw_lim-arr[n-idx-1])
    up_lim=min(w, up_lim-arr[n-idx-1])
print(max(0,up_lim-lw_lim+1))