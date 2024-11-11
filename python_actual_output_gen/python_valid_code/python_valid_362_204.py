n=str(input())
t=[]
for letter in n:
    t.append(letter)
b=list(set(t))
if len(b)%2==0:
    print('CHAT WITH HER')
else:
    print('IGNORE HIM')