
r = lambda: int(input())

n = r()
r_o = r()
r_e = r()
o_e = r()
m = min(r_o,r_e,o_e)
total = 0
total += min(r_o,r_e) if n>1 else 0
total += (n-2) * m if n>2 else 0
print (total)
