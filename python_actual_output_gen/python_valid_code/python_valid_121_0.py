def cell(num):
    if int(num) < num:
        return num + 1
    return num
n, k = map(int,input().split())
hi = list(map(int,input().split()))
hi.sort()
num = 0
if n == 1:
    print(0)
else:
    height = hi[-1]
    sumHeight = 0
    num2 = 1
    for i in range(n-2,-1,-1):
        sumHeight2 = sumHeight + num2 * (height - hi[i])
        if sumHeight2 == k:
            num += 1
            sumHeight = 0
        elif sumHeight2 > k:
            num5 = k // num2
            j = height
            num6 = sumHeight
            while num6 < k:
                num6 += num2
                j -= 1
            num += 1
            num += (j + 1 - hi[i]) // num5
            sumHeight = (j + 1 - hi[i]) % num5
        else:
            sumHeight = sumHeight2
        height = hi[i]
        num2 += 1
    if sumHeight > 0:
        num += 1
    print(num)
    
        
