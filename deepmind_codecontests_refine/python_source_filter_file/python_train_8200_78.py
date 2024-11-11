n = int(input())
a = map(int, input().split())

print('YNeos'[len(set(a))!=n::2])