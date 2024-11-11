while True:
 a=input()
 if a.find('?')>0:break
 print(eval(''.join(a.split())))