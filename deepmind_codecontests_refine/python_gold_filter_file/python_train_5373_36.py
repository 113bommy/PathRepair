s = input()
n = int(input())
if len(s)<n:
    print('impossible')
else:
    print(max(0,n-len(set(s))))