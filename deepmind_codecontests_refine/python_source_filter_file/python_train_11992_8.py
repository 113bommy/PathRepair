n = int(input())
tekst = str(input())
#var = [int(x) for x in input().split(' ')]

# lines = []var_sort
# for i in range(n):
#     line = input()
#     if line:
#         lines.append(line)
#     else:
#         break
# faces = 0

a = tekst.count('z')
b = tekst.count('n')
stri = ''
if b> 0:
    for i in range(b):
        stri+= '1 '
    for j in range(a):
        stri+= '0 '
else:
    print('0')

print(stri)
