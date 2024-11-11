s=input()
k=int(input())
if len(s)>=k:
    print(max(0,k-len(set(s))))
else:print('impossible')