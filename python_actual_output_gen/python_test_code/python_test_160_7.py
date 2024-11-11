n = int(input())
s = str(input())
j, i = n // 2, n // 2 + 1

# debug
# print(f'initial \n x = {j}, y = {i}')

while (j > 0 and s[j] == '0'):
    j-=1
while (i < n and s[i] == '0'):
    i+=1

# debug
# print(f'final\n x = {j}, y = {i}')

if j==0:
     print(int(s[0:i]) + int(s[i:n]))
     print('statement1')
elif i==n:
    print( int(s[0:j]) + int(s[j:n]))
    print('statement2')
else:
    print(min( int(s[:i])+  int(s[i:]), int(s[:j]) + int(s[j:])))
