n = input()
a, b = n.split(" ")
a = int(a)
b = int(b)
total = a
while a >= b:
      div = a//b
      total = total + div 
      mod = a%b 
      a = div - mod 
print(total)