n=input()
d={"9":"1","1":"9"}
print("".join(d[x] for x in n))