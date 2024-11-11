n = int(input())
a = sum(list(map(int,input().split()))) #volume remaining
b = sorted(list(map(int,input().split()))) #total volume

print(b[-2:],a)
print(['YES','NO'][sum(b[-2:])<a])