x=input()
x=x.replace("--","2")
x=x.replace("-.","1")
if "." in x:
  x=x.replace(".","0")
print(x)