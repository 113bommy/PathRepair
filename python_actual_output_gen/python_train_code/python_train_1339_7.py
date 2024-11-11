n = int(input())
from sys import stdin, stdout
map1 = map(int, stdin.readline().rstrip().split())
arra = list(map1)
arra.sort(reverse = True)
money = 0

for i in range(n):
    if sum(arra[:i+1]) >= sum(arra[i:]):
        print(i+1)
        break
    money += arra[i]

