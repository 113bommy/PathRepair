s = input()
t = input()
lett_pr = True
for letter in set(t):
    if s.count(letter)>=t.count(letter):
        pass
    else:
        
        lett_pr = False
        break

if lett_pr:
    if len(s)==len(t):
        print('array')
    else:
        pointer = 0
        counter = 0
        for i in range(len(s)):
            if s[i]==t[pointer]:
                counter+=1
                if counter==len(t):
                    break
                else:
                    pointer+=1
            else:
                pass
        if counter==len(t):
            print('automaton')
        else:
            print('array')
else:
    print('need tree')



