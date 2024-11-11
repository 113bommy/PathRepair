s = input ("")
t = input("")

less_pos = 0
for i in range (len(t)):
  if(t[i]==s[less_pos]):
    less_pos =less_pos +2
print(less_pos)