a,b = map(int, input().split())
s = '1'+'0'*(a-1)
for i in range(int(s),int(s+'0')):
    if i%2==0:print(i);exit()
print('-1')