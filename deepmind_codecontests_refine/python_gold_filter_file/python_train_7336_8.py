# Tran Duy_Big O Blue
s = list(input())
t = list(input())
check = True
equal = True
# for i in range(len(s)):
#     if ord(s[i])+1 >= ord(t[i]) and i == len(s)-1:
#         check = False
#         print(ord(s[i]))
#         print(ord(t[i]))
#         print(i)
#     elif ord(s[i])+1 < ord(t[i]):
#         check = True
#         s[i] = chr(ord(s[i])+1)
#         s = ''.join(s)
#         break
for i in range(len(s)-1, -1, -1):
    if s[i] == 'z':
        s[i] = 'a'
    else:
        s[i] = chr(ord(s[i])+1)
        break

for i in range(len(s)):
    if s[i] != t[i]:
        equal = False
        break
if equal is True:
    print('No such string')
    exit()

for i in range(len(s)):
    if ord(s[i]) > ord(t[i]):
        check = True
        break

if check is True:
    s = ''.join(s)
    print(s)
else:
    print('No such string')
    print(s)
