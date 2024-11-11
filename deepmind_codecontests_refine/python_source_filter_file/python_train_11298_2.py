def rename(s):
    return "women" if s == "woman" or s== "child" else s
def classify(d):
    s,r=input().split()
    if not d.get(rename(r)):
        d[rename(r)]=[s,]
    else:
        d[rename(r)].append(s)
    return d
n=int(input())
d={}
for i in range(n):
    d=classify(d)
for i in ["rat","women","man","captain"]:
    if d.get(i):
        print("\n".join(d[i]),"\n")