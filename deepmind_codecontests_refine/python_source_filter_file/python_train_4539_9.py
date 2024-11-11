def check(s,length):
    if length == 1:
        print(0)
        exit()
    if length == 2 and s != 'kv':
        print(1)
        exit()
    if length == 2 and s == 'kv':
        print(0)
        exit()

from sys import exit
s = input()
length = len(s)
check(s,length)
vkCount = s.count('VK')
flag = False
if 'VVV' in s or 'KKK' in s or s[-2:] == 'VV' or s[:3] == 'KK':
    flag = True
print(vkCount+1) if flag else print(vkCount)
