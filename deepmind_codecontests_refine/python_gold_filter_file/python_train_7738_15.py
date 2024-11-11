n, k = map(int, input().split())
def snt(n):
    for i in range(2,int(n**0.5) + 1):
        if n%i == 0: return False
    return True
if k == 0: print("YES"); exit()
lis = []
for i in range(3,n+1):
    if snt(i): lis.append(i)
cnt = 0
for a,b in zip(lis, lis[1:]):
    if (a + b + 1) in lis: cnt += 1
    if cnt == k: print("YES"); exit()
print("NO")
