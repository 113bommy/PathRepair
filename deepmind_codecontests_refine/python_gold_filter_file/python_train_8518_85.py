#coding:utf-8
import re
s = input()
#正規表現でひっかける
pattern = 'A?KIHA?BA?RA?$'
result = re.match(pattern , s)

if result:
    print('YES')
else:
    print('NO')