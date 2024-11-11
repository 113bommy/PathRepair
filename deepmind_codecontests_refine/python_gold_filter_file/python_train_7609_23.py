a=int(input())
b=list(map(int, input().split()))
print(max(b)-min(b)-a+1)