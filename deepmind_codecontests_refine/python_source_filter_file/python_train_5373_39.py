s=input()
k=int(input())
if len(s)>=k:
    print(k-len(set(s)))
else:print('impossible')