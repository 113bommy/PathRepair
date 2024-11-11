N = int(input())
i = 1
ans = 0
while i*i<N:
    temp = N//i-1
    if  N == i*temp+i and (N-i)/i > i:
        ans += temp
    i+=1
print(ans)

