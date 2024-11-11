n = int(input())
s = set(input().split())
print(len([x for x in s if x != '0']))