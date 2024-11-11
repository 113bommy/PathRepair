a,b,c,d=map(int,[input(),input(),input(),input()])
print(1-(((a|b)&(c^d))|((b&c)^(a|d))))
