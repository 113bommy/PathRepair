a = input()[2:]
b = input()[2:]
c = input()[2:]
d = input()[2:]
# print(a,'\n',b,'\n',c,'\n',d)
answer = ""
if (len(a)*2 <= len(b) and len(a)*2 <= len(c) and len(a)*2 <= len(d)) or (len(a) >= len(b)*2 and len(a) >= len(c)*2 and len(a) >= len(d)*2):
    answer += 'A'
if (len(b)*2 <= len(a) and len(b)*2 <= len(c) and len(b)*2 <= len(d)) or (len(b) >= len(a)*2 and len(b) >= len(c)*2 and len(b) >= len(d)*2):
    answer += 'B'
if (len(c)*2 <= len(b) and len(c)*2 <= len(a) and len(c)*2 <= len(d)) or (len(c) >= len(b)*2 and len(c) >= len(a)*2 and len(c) >= len(d)*2):
    answer += 'C'
if (len(d)*2 <= len(b) and len(d)*2 <= len(c) and len(d)*2 <= len(a)) or (len(d) >= len(b)*2 and len(d) >= len(c)*2 and len(d) >= len(a)*2):
    answer += 'D'
print(answer)
if len(answer) != 1:
    print('C')
else:
    print(answer)
