s=input()
B,u,l,b,a,s,r=s.count('B'),s.count('u'),s.count('l'),s.count('b'),s.count('a'),s.count('s'),s.count('r')
print(min(B,u//2,l,b//2,a//2,s,r))