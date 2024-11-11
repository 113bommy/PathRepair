n = input()
a = ''
for i in range(len(n)):
    if int(n[i]) < 5 or (i==0 and n[i]==9):
        a+=n[i]
    else:
        a+=str(9 - int(n[i]))
print(a)