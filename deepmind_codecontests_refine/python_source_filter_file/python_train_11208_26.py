k = int(input())
s = input()
k = 0
while 'xxx' in s:
    s = s.replace('x', '', 1)
    k += 1
print(k)
    
