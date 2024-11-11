s = input()
t = input()

s = s.replace(" ", "")
t = t.replace(" ", "")

reverse_s = ''


for i in s:
    reverse_s = i + reverse_s

if (t == reverse_s):
    print ("Yes")
else:
    print ("No")