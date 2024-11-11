n = int(input())
qx, qy = list(map(int, input().split()))
kx, ky = list(map(int, input().split()))
cx, cy = list(map(int, input().split()))

result = "NO"
if kx >= qx + 1 and ky >= qy + 1 and cx >= qx + 1 and cy >= qy + 1:
    result = "YES"
elif kx <= qx - 1 and ky <= qy - 1 and cx <= qx - 1 and cy <= qy - 1:
    result = "YES"
elif kx >= qx + 1 and ky <= qy - 1 and cx >= qx + 1 and cy <= qy - 1:
    result = "YES"
elif kx <= qx - 1 and ky >= qy + 1 and cx <= qx - 1 and cy >= qy + 1:
    result = "YES"
    
print(result)