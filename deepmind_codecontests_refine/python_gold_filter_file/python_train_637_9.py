l = list(map(int, input().split()))
n = [int(i)%2 for i in input().split()]
m = [int(i)%2 for i in input().split()]

print(min(n.count(0), m.count(1)) + min(n.count(1), m.count(0)))  