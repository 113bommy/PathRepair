n = int(input())
h = list(map(int,input().split()))
cnt = 0
for i in range(n-1):
    cnt +=min(h[i],h[i+1])
print(sum(h)-cnt)
