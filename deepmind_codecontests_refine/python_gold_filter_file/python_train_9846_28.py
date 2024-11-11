input()
s=list(map(int,input().split()))
print(sum(max(s)-i for i in s))