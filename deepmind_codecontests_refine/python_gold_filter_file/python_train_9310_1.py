t = input()
t = t.replace("dot", '.')
t = t.replace("at", '@')
if t.find('.')==0: t = t.replace(".", "dot", 1)
if t.find('@')==0: t = t.replace("@", "at", 1)
if t.rfind('.')==len(t)-1:
    t = t[0:len(t)-1]
    t += "dot"
if t.rfind('@')==len(t)-1:
    t = t[0:len(t)-1]
    t += "at"
fir = t.find('@')
pref = t[0:fir+1]
suf = t[fir+1:]
suf = suf.replace('@', "at")
print(pref+suf)