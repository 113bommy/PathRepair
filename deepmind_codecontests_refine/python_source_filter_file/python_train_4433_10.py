c=lambda s,i:s.count(i)
z=lambda:int(input())
x=lambda:input()
f=lambda:map(int,input().split())
n=z()
s=x()
l=[c(s,'A'),c(s,'C'),c(s,'G'),c(s,'T')]
if any(i>n//4 for i in l) or n%4!=0:
    exit(print('==='))
s=s.replace('?','A',n//4-l[0])
s=s.replace('?','C',n//4-l[1])
s=s.replace('?','G',n//4-l[2])
s=s.replace('?','T',n//4-l[3])
print(s,end='  ')
