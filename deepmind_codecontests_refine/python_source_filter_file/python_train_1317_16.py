import math as m

l = int(input())
s = input()

i=m.trunc(l/2)+1
t = 0
while i > 0:
    if s[0:i] == s[i:2*i]:
        t = i;
        break;
    i -= 1

print(l-t+1)