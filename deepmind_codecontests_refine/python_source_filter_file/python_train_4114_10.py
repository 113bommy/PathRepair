import re
l=re.split('[,,;]',input())
# print(l)
ans_int='-'
ans_str='-'
for i in l:
#     print(i)
    if re.match('^[1-9]+$|^0$', i) != None:
        if ans_int == '-':
            ans_int=i
        else:
            ans_int+=','+i
    elif i !='':
        if ans_str == '-':
            ans_str=i
        else:
            ans_str+=','+i
    elif ans_str=='-':
            ans_str=''
    else:
        ans_str+=','
if ans_int == '-':
    print(ans_int)
else:
    print('"'+ans_int+'"')
if ans_str=='-':
    print(ans_str)
else:
    print('"'+ans_str+'"')

