n , m = map(int,input().split())
ar = list()
for i in range(n):
    x = input()
    ar.append(x)

c = list(map(int,input().split()))
print(c)

ans = 0
for i in range(m):
    k = [0 for _ in range(5)]
    for j in range(n):
        k[ord(ar[j][i])-ord('A')]+=1
    # print(k)
    ans +=  max(k)*c[i]
print(ans)
