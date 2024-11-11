n = int(input())

s = input()
anton = 0
danik = 0
for i in range(len(s)):
    if s[i] == 'A':
        anton+=1
    else:
        danik+=1

if anton > danik:
    print('Anton')
elif anton < danik:
    print('Danik')
else:
    print('Friendship')
