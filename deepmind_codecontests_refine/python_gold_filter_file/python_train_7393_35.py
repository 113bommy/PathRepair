while True:
 a=input()
 if a.find('?')>0:break
 print(int(eval(''.join(a.split()))))