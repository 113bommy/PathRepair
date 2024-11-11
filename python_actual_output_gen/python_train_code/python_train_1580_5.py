a=input()
a=a.replace('vk','AA')
z=a.count('A')//2
a=a.replace('vv','W')
a=a.replace('kk','W')
if 'W' in a:
    z+=1
print(z)
