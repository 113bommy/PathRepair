a=list(input())
k=int(input())
if k>len(a):
    print('impossible')
else:
    print(k-len(set(a)))