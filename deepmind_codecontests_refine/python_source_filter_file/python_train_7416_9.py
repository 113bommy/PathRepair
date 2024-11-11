t = int(input())
H = []
for k in range(1, 8501):
    H.append((k*(3*k+1)/2))

def noOFpyramid(num):
    c = 0
    if num> 1:
        j = 0
        while j < 8500:
            if num < H[j]:
                num = num - H[j-1]
                c += 1
                return c+ noOFpyramid(num)
            j += 1
    else:
        return 0

for i in range(t):
    n = int(input())
    x = noOFpyramid(n)
    print(x)