s=input()
print("AC"if s[0]=='A'and s.count('C',2,-2)==1 and s[1:].replace('C','',1).islower()else"WA")