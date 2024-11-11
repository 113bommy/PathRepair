input()
s=map(int,input().split())
print(sum(max(s)-i for i in s))