
# C
H, W = map(int, input().split())
 
res = min(H, W)
# split H
for h in range(H // 3, H // 3 + 2):
    w = W // 2
    s1 = h*W
    s2 = (H-h)*w
    s3 = (H-h)*(W-w)
    res = min(res, max(s1,s2,s3) - min(s1,s2,s3))
# split W
for w in range(W // 3, W // 3 + 2):
    h = H // 2
    s1 = w*H
    s2 = (W-w)*h
    s3 = (W-w)*(H-h)
    res = min(res, max(s1,s2,s3) - min(s1,s2,s3))
    
# 3
if H % 3 == 0 or W % 3 == 0:
    res = 0
print(res)

