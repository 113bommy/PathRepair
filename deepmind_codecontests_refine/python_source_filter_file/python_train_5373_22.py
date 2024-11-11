a=list(input())
k=int(input())
if k>len(a):
    print('Impossible')
else:
    print(k-len(set(a)))