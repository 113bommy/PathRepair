n=int(input())
h=list(map(int,input().split()))
print(sum(max(h[:i])<=h[i]for i in range(n)))