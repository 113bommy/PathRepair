n=int(input())

s=input()
s=s.upper()
s1="A"
s2="D"
c1=s.count(s1)
c2=s.count(s2)
    
if c1>c2:
    print("Antony")
elif c1==c2:
    print("Friendship")
else:
    print("Drake")