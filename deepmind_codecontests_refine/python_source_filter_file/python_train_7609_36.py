n=int(input())
s=list(map(int,input().split()))
print(max(s)-min(s)+4-n)