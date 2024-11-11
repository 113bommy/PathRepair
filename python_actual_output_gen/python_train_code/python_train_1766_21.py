N = int(input())
s = [int(x) for x in input().split()]
s = [0,0,0,0,0] + s + [0,0,0,0,0]
k = 0
for i in range(N):
    if s[i]==1 and s[i+1]==0 and s[i+2]==1:
        s[i+2] = 0
        k += 1
print(k)
