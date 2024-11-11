length = int(input())
s = input()
num_l = s.count("L")
num_r = s.count("R")
num_u = s.count("U")
num_d = s.count("D")

val = 0
if num_l < num_r:
    val += num_l
else:
    val += num_r
if num_u < num_d:
    val += num_u
else:
    val += num_d
    
print(val)