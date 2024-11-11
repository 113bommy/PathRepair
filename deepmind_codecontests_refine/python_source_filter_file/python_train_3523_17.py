H, W = map(int,input().split())
N = int(input())
A = list(map(int,input().split()))
ans = [0]*(H*W)
cnt = 0
for idx,a in enumerate(A):
    for i in range(a):
        ans[cnt+i] = idx+1
    cnt += a
print(ans)
# ans　をWずつ折り返して表示
for h in range(H):
    if h % 2 == 0:
        print(*ans[h*W:(h+1)*W])
    else:
        temp = ans[h*W:(h+1)*W]
        print(*temp[::-1])
        
        #print(*ans[h*W:(h+1)*W:-1])

