import math

s = input()
n_count = s.count("n")
e_count = s.count("e")

n = math.floor((n_count - 1) / 2)
e = math.floor(e_count/3)

i = s.count("i")
t = s.count("t")

print(min(n,i,t,e))
