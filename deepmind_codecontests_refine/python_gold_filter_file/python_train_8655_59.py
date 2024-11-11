t=input()
j=t.count("a")
if j>len(t)-j:
    print(len(t))
else:
    print(2*j-1)