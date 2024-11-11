s=input()
l=[]
for i in range(len(s)-1):
    l.append(s[-1]+s[:len(s)-1])
    s=l[-1]
print(len(set(l)))