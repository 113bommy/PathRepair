t=input()
j=t.count("a")
if j>=(len(t)//2):
    print(len(t))
else:
    print(2*j-1)