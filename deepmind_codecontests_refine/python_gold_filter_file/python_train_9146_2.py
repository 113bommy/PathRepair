import re
out=[]
for w in input().split(" "):
    if re.search("apple",w)!=None:out.append(re.sub("apple","peach",w))
    elif re.search("peach",w)!=None:out.append(re.sub("peach","apple",w))
    else:out.append(w)
print(' '.join(out))