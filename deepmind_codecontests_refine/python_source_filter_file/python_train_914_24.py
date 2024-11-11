n=int(input())
h=list(map(int,input().split()))
print(count(max(h[:i])<=h[i]for i in range(n)))