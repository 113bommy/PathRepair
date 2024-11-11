s=input()
print(["Bad","Yes"][len(set(s))==2 and s.count(s[0])==2])