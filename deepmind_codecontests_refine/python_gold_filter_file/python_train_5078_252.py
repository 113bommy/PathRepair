import re
a,b,c=map(int, re.split("[ .]",input()))
print(a*(b*100+c)//100)