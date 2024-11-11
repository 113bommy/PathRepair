coding:utf-8
import re
s = input()
#正規表現でひっかける
pattern = 'A?KIHA?BARA?$'
result = re.match(pattern , s)

if result:
    print('Yes')
else:
    print('No')