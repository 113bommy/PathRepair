n = int(input())
l = list(map(int,input().split()))
k = [l[i-1]+l[i] for i in range(1,n)]
k.append(l[-1])
print(*k)
