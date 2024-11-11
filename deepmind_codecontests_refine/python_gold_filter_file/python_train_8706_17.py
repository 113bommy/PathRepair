k1, k2, k3 = sorted(list(map(int, input().split())))[::-1]
b = k3==1 or (k1==3 and k2==3 and k3==3) or (k3==2 and (k2==2 or (k2==4 and k1==4)))
print('YES' if b else 'NO')
