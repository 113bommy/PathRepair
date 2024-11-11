s=input()
l,t=len(s),1
for i in range(l):
    for j in range(i+1,l):
        if s[:i]+s[j:]=="CODEFORCES":t=0
print("YNEOS"[t::2])