n = int(input())
m = [list(map(int, input().split())) for i in range(n)]
# print(m)
m.sort(key=lambda x:x[1]-x[0])
print(sum(m[j][0]*(j)+m[j][1]*(n-j-1)) for j in range(n))