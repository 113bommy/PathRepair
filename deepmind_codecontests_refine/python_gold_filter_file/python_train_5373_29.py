a=list(input())
k=int(input())
if k>len(a):
    print('impossible')
else:
    print(max(0,k-len(set(a))))