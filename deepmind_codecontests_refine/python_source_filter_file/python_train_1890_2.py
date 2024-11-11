a=input()
b=a.replace('a','')
x=len(b)//2
if x<1: print(a)
else: print([a[:-x],':('][b[:-x]!=b[-x:] or a[-x:].count('a')>0])
