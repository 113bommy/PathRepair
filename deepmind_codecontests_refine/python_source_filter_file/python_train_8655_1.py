a=input()
if a.count('a')>=len(a)//2:
    print(len(a))
else:
    print(2*a.count('a')-1)
