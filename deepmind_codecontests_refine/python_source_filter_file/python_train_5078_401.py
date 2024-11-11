import re
a,b,c=map(int, re.split("[ .]",input()))
print(int(a*(b*100+c)/100))