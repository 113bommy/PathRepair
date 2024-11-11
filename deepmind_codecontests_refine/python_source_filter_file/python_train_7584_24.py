a,b,c,=list(input()),list(input()),list(input())
d=a[0]
e=0
a.remove(d)
while True:
    if eval(d)==[]:
        break
    e=eval(d)[0]
    eval(d).remove(e)
    d=e
print(str.upper(e))