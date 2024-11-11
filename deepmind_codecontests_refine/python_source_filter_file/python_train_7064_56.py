#coding: utf-8

import re

s = input()
if re.search("C.*F", s) is not None:
    print('Yes')
else:
    print('None')
