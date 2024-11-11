n=int(input())
h=list(map(int,input().split()))
print(count(max(h[:i]+[0])<=h[i]for i in range(n)))