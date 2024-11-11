k, t = list(map(int, input().split()))
a = list(map(int, input().split()))

M = max(a)
print(max(0, 2*(M-(k//2+1))+1+k%2))