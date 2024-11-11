s = input()
a = input()
b = input()
ab = a+b
sin = s[::-1];

if ((s.find(a)>=0) and (s[s.find(a)+len(a):].find(b) )>=0) and ((sin.find(a)>=0) and (sin[sin.find(a)+len(a):].find(b))>=0):
  print("both")
elif ((s.find(a)>=0) and (s[s.find(a)+len(a):].find(b) )>=0):
  print("forward")
elif ((sin.find(a)>=0) and (sin[sin.find(a)+len(a):].find(b))>=0):
  print("backward")
else:
  print("fantasy")
  
