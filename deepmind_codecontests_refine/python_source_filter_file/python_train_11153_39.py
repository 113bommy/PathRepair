n = int(input())
m = input()
s = []
s.append('A')
for i in range(0,n,1):
    s.append(m[i])
s.append('A')
ch = 0
for i in range(1,n+2,1):
    if s[i] == s[i-1]:
        ch += 1
        if(s[i] == 'R'):
           if(s[i+1] == 'G'):
               s[i] = 'B'
           else:
               s[i] = 'G'
        elif(s[i] == 'G'):
           if(s[i+1] == 'R'):
               s[i] = 'B'
           else:
               s[i] = 'R'
        else:
           if(s[i+1] == 'R'):
               s[i] = 'G'
           else:
               s[i] = 'R'

print(ch)
for i in range(1,n+2,1):
    print(s[i], end = '')
