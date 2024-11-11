def f(a,b):
    if a==b:return False
    if ord(a[0])<ord(b[0]):return True
    if ord(a[0])>ord(b[0]):return False
    return f(a[1:],b[1:])
def g(a):
    if a[-1]=='z':return g(a[:-1])+'a'
    return a[:-1]+chr(ord(a[-1])+1)
a=g(input())
b=input()
print(a if f(a,b)else'No such string')
