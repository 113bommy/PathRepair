list1 = list(map(int,input().split()))
a = [1,3]
print('YES' if (list1[0]//list1[1])%4 in a else 'NO')