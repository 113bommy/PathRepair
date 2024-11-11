N = int(input())
src = [input() for i in range(N)]

def isok(b):
    for i in range(N-1):
        for j in range(i+1, N):
            i2 = (i+b)%N
            j2 = (j+b)%N
            if src[i][j2] != src[j][i2]:
                return False
    return True

ans = 0
for i in range(-N+1,N):
    if isok(i):
        ans += N-abs(i)
print(ans)