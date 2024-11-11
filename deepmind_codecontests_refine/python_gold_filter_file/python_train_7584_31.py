#045_B
S={}
S['a']=list(input())
S['b']=list(input())
S['c']=list(input())
s='a'
while len(S[s]):
    s=S[s].pop(0)
print(s.upper())