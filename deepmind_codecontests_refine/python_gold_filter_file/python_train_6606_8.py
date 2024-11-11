from math import factorial as f
s1=input()
s2=input()
plus=s1.count('+')-s2.count('+')
minus=s1.count('-')-s2.count('-')
quest=s2.count('?')
if plus<0 or minus<0:
    print(0)
else:
    print((f(quest)/(f(plus)*f(minus)))/(2**quest))