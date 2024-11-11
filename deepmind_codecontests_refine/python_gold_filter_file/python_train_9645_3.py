# https://vjudge.net/contest/319028#problem/C

n = int(input())
scores = { int(x) for x in input().split() if int(x) != 0 }

jeitos = len(scores)

print(jeitos)