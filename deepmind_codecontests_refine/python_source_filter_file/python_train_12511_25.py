from collections import defaultdict

n, k = [int(i) for i in input().split()]

# 2left + actions - actions^2 = - eat(2actions - eat - 3)
# add = actions - eat

for add in range(1,n):
    eat = n - add
    if add * (add+1) == 2*(k + eat):
        print(eat)
        break

