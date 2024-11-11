n=int(input())
h=list(map(int,input().split()))
print(sum(max(h[:i]+[0])<=h[i]for i in range(n)))