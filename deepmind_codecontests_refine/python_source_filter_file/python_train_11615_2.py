
form = input()
h, m = input().split(":")

out = ""

if form == "12":
  if int(h) > 12:
    if h[1] == "0":
      out += "%d0:" % (1)
    else:
      out += "0%s" % h[1]
  else:
    if h[1] == "0":
      out += "01:"
    else:
      out += h + ":"
      
  if int(m) > 59:
    out += "0%s" % m[1]
  else:
    out += m
  

else:
  if int(h) > 23:
    out += "0%s:" % h[1]
  else:
    out += h + ":"
  
  if int(m) > 59:
    out += "0%s" % m[1]
  else:
    out += m
  
print(out)
  
