num = input().split(" ")
num = [int(i) for i in num]
if num[0]%num[1]==0: print("-1")
else: print(num[0])