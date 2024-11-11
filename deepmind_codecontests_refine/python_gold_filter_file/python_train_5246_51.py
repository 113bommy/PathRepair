x=int(input())
l=input()

if l.count('R')+l.count('.')==len(l):
    print(l.find('R')+1,l.rfind('R')+2)
    
elif l.count('L')+l.count('.')==len(l):
    print(l.rfind('L')+1,l.find('L'))

else:
    print(l.find('R')+1,l.rfind('R')+1)