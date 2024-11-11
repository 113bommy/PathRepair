from functools import cmp_to_key
n = int(input())
stg = []
for i in range(n):
    stg.append(input())
stg = sorted(stg,key = cmp_to_key(lambda a,b:True if a + b > b + a else False))
print(''.join(stg))
