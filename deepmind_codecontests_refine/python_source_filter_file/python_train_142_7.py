inp = input().split("+")
one, two, three = "","",""

for i in inp:
    if i=='1+':
        one+='1'
    elif i=='2':
        two+='2+'
    else:
        three+='3+'
        
out = one + two + three
        
print(out[:-1])
        