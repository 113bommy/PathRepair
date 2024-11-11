i=input;i();l=i().split();x=1-('0'in l)
for j in l:
  x*=j-48
  if x>1e18:
    print(-1);quit()
print(x)
