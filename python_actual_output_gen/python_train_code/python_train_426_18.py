string = input()
pre = -1
ans = 0
for index,char in zip(range(len(string)),string):
    if char in 'AEIOUY':
       ans = max(ans,index - pre)
       pre = index
print(ans)