import math

def main(H,W):
    ans = float('inf')
    w = math.floor(W / 2)
    for i in range(H):
        Smin = min(i * W, w * (H - i), (W - w) * (H - i))
        Smax = max(i * W, w * (H - i), (W - w) * (H - i))
        ans = min(ans, Smax-Smin)
    return min(H,ans)

H, W = map(int, input().split())
    
if H % 3 == 0 or W % 3 == 0:
    print(0)
else:
    print(min(main(H,W), main(W,H)))